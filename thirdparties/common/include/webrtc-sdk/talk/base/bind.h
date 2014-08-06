// This file was GENERATED by command:
//     pump.py bind.h.pump
// DO NOT EDIT BY HAND!!!

/*
 * libjingle
 * Copyright 2012 Google Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// To generate bind.h from bind.h.pump, execute:
// /home/build/google3/third_party/gtest/scripts/pump.py bind.h.pump

// Bind() is an overloaded function that converts method calls into function
// objects (aka functors). It captures any arguments to the method by value
// when Bind is called, producing a stateful, nullary function object. Care
// should be taken about the lifetime of objects captured by Bind(); the
// returned functor knows nothing about the lifetime of the method's object or
// any arguments passed by pointer, and calling the functor with a destroyed
// object will surely do bad things.
//
// Example usage:
//   struct Foo {
//     int Test1() { return 42; }
//     int Test2() const { return 52; }
//     int Test3(int x) { return x*x; }
//     float Test4(int x, float y) { return x + y; }
//   };
//
//   int main() {
//     Foo foo;
//     cout << talk_base::Bind(&Foo::Test1, &foo)() << endl;
//     cout << talk_base::Bind(&Foo::Test2, &foo)() << endl;
//     cout << talk_base::Bind(&Foo::Test3, &foo, 3)() << endl;
//     cout << talk_base::Bind(&Foo::Test4, &foo, 7, 8.5f)() << endl;
//   }

#ifndef TALK_BASE_BIND_H_
#define TALK_BASE_BIND_H_

#define NONAME

namespace talk_base {
namespace detail {
// This is needed because the template parameters in Bind can't be resolved
// if they're used both as parameters of the function pointer type and as
// parameters to Bind itself: the function pointer parameters are exact
// matches to the function prototype, but the parameters to bind have
// references stripped. This trick allows the compiler to dictate the Bind
// parameter types rather than deduce them.
template <class T> struct identity { typedef T type; };
}  // namespace detail

template <class ObjectT, class MethodT, class R>
class MethodFunctor0 {
 public:
  MethodFunctor0(MethodT method, ObjectT* object)
      : method_(method), object_(object) {}
  R operator()() const {
    return (object_->*method_)(); }
 private:
  MethodT method_;
  ObjectT* object_;
};

template <class FunctorT, class R>
class Functor0 {
 public:
  explicit Functor0(const FunctorT& functor)
      : functor_(functor) {}
  R operator()() const {
    return functor_(); }
 private:
  FunctorT functor_;
};


#define FP_T(x) R (ObjectT::*x)()

template <class ObjectT, class R>
MethodFunctor0<ObjectT, FP_T(NONAME), R>
Bind(FP_T(method), ObjectT* object) {
  return MethodFunctor0<ObjectT, FP_T(NONAME), R>(
      method, object);
}

#undef FP_T
#define FP_T(x) R (ObjectT::*x)() const

template <class ObjectT, class R>
MethodFunctor0<const ObjectT, FP_T(NONAME), R>
Bind(FP_T(method), const ObjectT* object) {
  return MethodFunctor0<const ObjectT, FP_T(NONAME), R>(
      method, object);
}

#undef FP_T
#define FP_T(x) R (*x)()

template <class R>
Functor0<FP_T(NONAME), R>
Bind(FP_T(function)) {
  return Functor0<FP_T(NONAME), R>(
      function);
}

#undef FP_T

template <class ObjectT, class MethodT, class R,
          class P1>
class MethodFunctor1 {
 public:
  MethodFunctor1(MethodT method, ObjectT* object,
                 P1 p1)
      : method_(method), object_(object),
      p1_(p1) {}
  R operator()() const {
    return (object_->*method_)(p1_); }
 private:
  MethodT method_;
  ObjectT* object_;
  P1 p1_;
};

template <class FunctorT, class R,
          class P1>
class Functor1 {
 public:
  Functor1(const FunctorT& functor, P1 p1)
      : functor_(functor),
      p1_(p1) {}
  R operator()() const {
    return functor_(p1_); }
 private:
  FunctorT functor_;
  P1 p1_;
};


#define FP_T(x) R (ObjectT::*x)(P1)

template <class ObjectT, class R,
          class P1>
MethodFunctor1<ObjectT, FP_T(NONAME), R, P1>
Bind(FP_T(method), ObjectT* object,
     typename detail::identity<P1>::type p1) {
  return MethodFunctor1<ObjectT, FP_T(NONAME), R, P1>(
      method, object, p1);
}

#undef FP_T
#define FP_T(x) R (ObjectT::*x)(P1) const

template <class ObjectT, class R,
          class P1>
MethodFunctor1<const ObjectT, FP_T(NONAME), R, P1>
Bind(FP_T(method), const ObjectT* object,
     typename detail::identity<P1>::type p1) {
  return MethodFunctor1<const ObjectT, FP_T(NONAME), R, P1>(
      method, object, p1);
}

#undef FP_T
#define FP_T(x) R (*x)(P1)

template <class R,
          class P1>
Functor1<FP_T(NONAME), R, P1>
Bind(FP_T(function),
     typename detail::identity<P1>::type p1) {
  return Functor1<FP_T(NONAME), R, P1>(
      function, p1);
}

#undef FP_T

template <class ObjectT, class MethodT, class R,
          class P1,
          class P2>
class MethodFunctor2 {
 public:
  MethodFunctor2(MethodT method, ObjectT* object,
                 P1 p1,
                 P2 p2)
      : method_(method), object_(object),
      p1_(p1),
      p2_(p2) {}
  R operator()() const {
    return (object_->*method_)(p1_, p2_); }
 private:
  MethodT method_;
  ObjectT* object_;
  P1 p1_;
  P2 p2_;
};

template <class FunctorT, class R,
          class P1,
          class P2>
class Functor2 {
 public:
  Functor2(const FunctorT& functor, P1 p1, P2 p2)
      : functor_(functor),
      p1_(p1),
      p2_(p2) {}
  R operator()() const {
    return functor_(p1_, p2_); }
 private:
  FunctorT functor_;
  P1 p1_;
  P2 p2_;
};


#define FP_T(x) R (ObjectT::*x)(P1, P2)

template <class ObjectT, class R,
          class P1,
          class P2>
MethodFunctor2<ObjectT, FP_T(NONAME), R, P1, P2>
Bind(FP_T(method), ObjectT* object,
     typename detail::identity<P1>::type p1,
     typename detail::identity<P2>::type p2) {
  return MethodFunctor2<ObjectT, FP_T(NONAME), R, P1, P2>(
      method, object, p1, p2);
}

#undef FP_T
#define FP_T(x) R (ObjectT::*x)(P1, P2) const

template <class ObjectT, class R,
          class P1,
          class P2>
MethodFunctor2<const ObjectT, FP_T(NONAME), R, P1, P2>
Bind(FP_T(method), const ObjectT* object,
     typename detail::identity<P1>::type p1,
     typename detail::identity<P2>::type p2) {
  return MethodFunctor2<const ObjectT, FP_T(NONAME), R, P1, P2>(
      method, object, p1, p2);
}

#undef FP_T
#define FP_T(x) R (*x)(P1, P2)

template <class R,
          class P1,
          class P2>
Functor2<FP_T(NONAME), R, P1, P2>
Bind(FP_T(function),
     typename detail::identity<P1>::type p1,
     typename detail::identity<P2>::type p2) {
  return Functor2<FP_T(NONAME), R, P1, P2>(
      function, p1, p2);
}

#undef FP_T

template <class ObjectT, class MethodT, class R,
          class P1,
          class P2,
          class P3>
class MethodFunctor3 {
 public:
  MethodFunctor3(MethodT method, ObjectT* object,
                 P1 p1,
                 P2 p2,
                 P3 p3)
      : method_(method), object_(object),
      p1_(p1),
      p2_(p2),
      p3_(p3) {}
  R operator()() const {
    return (object_->*method_)(p1_, p2_, p3_); }
 private:
  MethodT method_;
  ObjectT* object_;
  P1 p1_;
  P2 p2_;
  P3 p3_;
};

template <class FunctorT, class R,
          class P1,
          class P2,
          class P3>
class Functor3 {
 public:
  Functor3(const FunctorT& functor, P1 p1, P2 p2, P3 p3)
      : functor_(functor),
      p1_(p1),
      p2_(p2),
      p3_(p3) {}
  R operator()() const {
    return functor_(p1_, p2_, p3_); }
 private:
  FunctorT functor_;
  P1 p1_;
  P2 p2_;
  P3 p3_;
};


#define FP_T(x) R (ObjectT::*x)(P1, P2, P3)

template <class ObjectT, class R,
          class P1,
          class P2,
          class P3>
MethodFunctor3<ObjectT, FP_T(NONAME), R, P1, P2, P3>
Bind(FP_T(method), ObjectT* object,
     typename detail::identity<P1>::type p1,
     typename detail::identity<P2>::type p2,
     typename detail::identity<P3>::type p3) {
  return MethodFunctor3<ObjectT, FP_T(NONAME), R, P1, P2, P3>(
      method, object, p1, p2, p3);
}

#undef FP_T
#define FP_T(x) R (ObjectT::*x)(P1, P2, P3) const

template <class ObjectT, class R,
          class P1,
          class P2,
          class P3>
MethodFunctor3<const ObjectT, FP_T(NONAME), R, P1, P2, P3>
Bind(FP_T(method), const ObjectT* object,
     typename detail::identity<P1>::type p1,
     typename detail::identity<P2>::type p2,
     typename detail::identity<P3>::type p3) {
  return MethodFunctor3<const ObjectT, FP_T(NONAME), R, P1, P2, P3>(
      method, object, p1, p2, p3);
}

#undef FP_T
#define FP_T(x) R (*x)(P1, P2, P3)

template <class R,
          class P1,
          class P2,
          class P3>
Functor3<FP_T(NONAME), R, P1, P2, P3>
Bind(FP_T(function),
     typename detail::identity<P1>::type p1,
     typename detail::identity<P2>::type p2,
     typename detail::identity<P3>::type p3) {
  return Functor3<FP_T(NONAME), R, P1, P2, P3>(
      function, p1, p2, p3);
}

#undef FP_T

template <class ObjectT, class MethodT, class R,
          class P1,
          class P2,
          class P3,
          class P4>
class MethodFunctor4 {
 public:
  MethodFunctor4(MethodT method, ObjectT* object,
                 P1 p1,
                 P2 p2,
                 P3 p3,
                 P4 p4)
      : method_(method), object_(object),
      p1_(p1),
      p2_(p2),
      p3_(p3),
      p4_(p4) {}
  R operator()() const {
    return (object_->*method_)(p1_, p2_, p3_, p4_); }
 private:
  MethodT method_;
  ObjectT* object_;
  P1 p1_;
  P2 p2_;
  P3 p3_;
  P4 p4_;
};

template <class FunctorT, class R,
          class P1,
          class P2,
          class P3,
          class P4>
class Functor4 {
 public:
  Functor4(const FunctorT& functor, P1 p1, P2 p2, P3 p3, P4 p4)
      : functor_(functor),
      p1_(p1),
      p2_(p2),
      p3_(p3),
      p4_(p4) {}
  R operator()() const {
    return functor_(p1_, p2_, p3_, p4_); }
 private:
  FunctorT functor_;
  P1 p1_;
  P2 p2_;
  P3 p3_;
  P4 p4_;
};


#define FP_T(x) R (ObjectT::*x)(P1, P2, P3, P4)

template <class ObjectT, class R,
          class P1,
          class P2,
          class P3,
          class P4>
MethodFunctor4<ObjectT, FP_T(NONAME), R, P1, P2, P3, P4>
Bind(FP_T(method), ObjectT* object,
     typename detail::identity<P1>::type p1,
     typename detail::identity<P2>::type p2,
     typename detail::identity<P3>::type p3,
     typename detail::identity<P4>::type p4) {
  return MethodFunctor4<ObjectT, FP_T(NONAME), R, P1, P2, P3, P4>(
      method, object, p1, p2, p3, p4);
}

#undef FP_T
#define FP_T(x) R (ObjectT::*x)(P1, P2, P3, P4) const

template <class ObjectT, class R,
          class P1,
          class P2,
          class P3,
          class P4>
MethodFunctor4<const ObjectT, FP_T(NONAME), R, P1, P2, P3, P4>
Bind(FP_T(method), const ObjectT* object,
     typename detail::identity<P1>::type p1,
     typename detail::identity<P2>::type p2,
     typename detail::identity<P3>::type p3,
     typename detail::identity<P4>::type p4) {
  return MethodFunctor4<const ObjectT, FP_T(NONAME), R, P1, P2, P3, P4>(
      method, object, p1, p2, p3, p4);
}

#undef FP_T
#define FP_T(x) R (*x)(P1, P2, P3, P4)

template <class R,
          class P1,
          class P2,
          class P3,
          class P4>
Functor4<FP_T(NONAME), R, P1, P2, P3, P4>
Bind(FP_T(function),
     typename detail::identity<P1>::type p1,
     typename detail::identity<P2>::type p2,
     typename detail::identity<P3>::type p3,
     typename detail::identity<P4>::type p4) {
  return Functor4<FP_T(NONAME), R, P1, P2, P3, P4>(
      function, p1, p2, p3, p4);
}

#undef FP_T

template <class ObjectT, class MethodT, class R,
          class P1,
          class P2,
          class P3,
          class P4,
          class P5>
class MethodFunctor5 {
 public:
  MethodFunctor5(MethodT method, ObjectT* object,
                 P1 p1,
                 P2 p2,
                 P3 p3,
                 P4 p4,
                 P5 p5)
      : method_(method), object_(object),
      p1_(p1),
      p2_(p2),
      p3_(p3),
      p4_(p4),
      p5_(p5) {}
  R operator()() const {
    return (object_->*method_)(p1_, p2_, p3_, p4_, p5_); }
 private:
  MethodT method_;
  ObjectT* object_;
  P1 p1_;
  P2 p2_;
  P3 p3_;
  P4 p4_;
  P5 p5_;
};

template <class FunctorT, class R,
          class P1,
          class P2,
          class P3,
          class P4,
          class P5>
class Functor5 {
 public:
  Functor5(const FunctorT& functor, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
      : functor_(functor),
      p1_(p1),
      p2_(p2),
      p3_(p3),
      p4_(p4),
      p5_(p5) {}
  R operator()() const {
    return functor_(p1_, p2_, p3_, p4_, p5_); }
 private:
  FunctorT functor_;
  P1 p1_;
  P2 p2_;
  P3 p3_;
  P4 p4_;
  P5 p5_;
};


#define FP_T(x) R (ObjectT::*x)(P1, P2, P3, P4, P5)

template <class ObjectT, class R,
          class P1,
          class P2,
          class P3,
          class P4,
          class P5>
MethodFunctor5<ObjectT, FP_T(NONAME), R, P1, P2, P3, P4, P5>
Bind(FP_T(method), ObjectT* object,
     typename detail::identity<P1>::type p1,
     typename detail::identity<P2>::type p2,
     typename detail::identity<P3>::type p3,
     typename detail::identity<P4>::type p4,
     typename detail::identity<P5>::type p5) {
  return MethodFunctor5<ObjectT, FP_T(NONAME), R, P1, P2, P3, P4, P5>(
      method, object, p1, p2, p3, p4, p5);
}

#undef FP_T
#define FP_T(x) R (ObjectT::*x)(P1, P2, P3, P4, P5) const

template <class ObjectT, class R,
          class P1,
          class P2,
          class P3,
          class P4,
          class P5>
MethodFunctor5<const ObjectT, FP_T(NONAME), R, P1, P2, P3, P4, P5>
Bind(FP_T(method), const ObjectT* object,
     typename detail::identity<P1>::type p1,
     typename detail::identity<P2>::type p2,
     typename detail::identity<P3>::type p3,
     typename detail::identity<P4>::type p4,
     typename detail::identity<P5>::type p5) {
  return MethodFunctor5<const ObjectT, FP_T(NONAME), R, P1, P2, P3, P4, P5>(
      method, object, p1, p2, p3, p4, p5);
}

#undef FP_T
#define FP_T(x) R (*x)(P1, P2, P3, P4, P5)

template <class R,
          class P1,
          class P2,
          class P3,
          class P4,
          class P5>
Functor5<FP_T(NONAME), R, P1, P2, P3, P4, P5>
Bind(FP_T(function),
     typename detail::identity<P1>::type p1,
     typename detail::identity<P2>::type p2,
     typename detail::identity<P3>::type p3,
     typename detail::identity<P4>::type p4,
     typename detail::identity<P5>::type p5) {
  return Functor5<FP_T(NONAME), R, P1, P2, P3, P4, P5>(
      function, p1, p2, p3, p4, p5);
}

#undef FP_T

}  // namespace talk_base

#undef NONAME

#endif  // TALK_BASE_BIND_H_
