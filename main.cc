#include <cstdio>

#include <deque>
#include <utility>

#include <boost/coroutine/all.hpp>


struct task {
  template <typename Fn>
  task(Fn&& fn) : more{[fn = std::forward<Fn>(fn)](auto& yield) mutable { std::forward<Fn>(fn)(yield); }} { }

  enum class state { ready, done };

  state operator()() {
    if (!more)
      return state::done;

    more();

    return more ? state::ready : state::done;
  }

  boost::coroutines::asymmetric_coroutine<void>::pull_type more;
};


struct scheduler {
  template <typename Fn>
  void schedule(Fn&& fn) {
    rq.emplace_back(std::forward<Fn>(fn));
  }

  void operator()() {
    while (!rq.empty()) {
      auto& next = rq.front();

      const auto state = next();

      if (state != task::state::done)
        rq.push_back(std::move(next));

      rq.pop_front();
    }
  }

  std::deque<task> rq;
};


int main() {
  const auto work = [](auto& yield) {
    std::puts("1");
    yield();
    std::puts("2");
    yield();
    std::puts("3");
  };

  scheduler sched;
  sched.schedule(work);
  sched.schedule(work);
  sched();
}
