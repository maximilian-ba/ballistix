# ADR 0001: Static Abstraction for Core Components

**Status:** Accepted  
**Date:** 2026-05-06

## Context
The simulation engine consists of various mathematical components—such as solvers (integrators) and force models (physics)—that must be modular and interchangeable.

We face the following constraints:

* **Performance Requirements**: These components are executed millions of times per second within the inner loops of the simulation. Any abstraction overhead must be minimized to maintain high frame rates or throughput.

* **Modularity**: Developers need to add new physical models (Forces) or numerical methods (Solvers) without modifying the core engine logic.

* **Type Safety & Maintainability**: The interfaces must be clearly defined to ensure that interchangeable components implement the expected signatures and behaviors, providing clear feedback during development.


## Decision

We will use Static Polymorphism using C++ Templates and C++20 Concepts.

Instead of using runtime interfaces (virtual functions), the core algorithms will be implemented as templates. The requirements for the types (e.g., what a Force or a Solver must look like) are explicitly defined using C++20 Concepts.

This allows the compiler to:

* **Inline** function calls directly, removing the cost of abstraction.

* Perform specific optimizations for each unique combination of force model and solver.

* Provide clear, readable compile-time errors if a component does not meet the interface requirements.


## Consequences

#### Positive

* **Zero-Cost Abstraction**: No runtime overhead from vtable lookups or indirect branching.

* **Optimization Potential**: Enables aggressive inlining and loop vectorization across component boundaries.

* **Self-Documenting Code**: Concepts serve as a machine-testable specification of the interfaces.

#### Negative

* **Compilation Time**: Header dependencies and compile times may increase due to template instantiation.

* **No Native Runtime Swapping**: Swapping models at runtime (without additional wrappers like type erasure) is not possible; configuration happens at compile-time.

* **Binary Size**: Frequent template instantiation can lead to "code bloat" (larger executable size).

## Alternatives

#### 1. Dynamic Polymorphism (Abstract Base Classes)

Using virtual methods for Forces and Solvers.

**Reason for Rejection**: The overhead of indirect calls and the prevention of compiler inlining are unacceptable for the target simulation frequency.

#### 2. Type Erasure (e.g., std::function)

Wrapping logic in universal function containers.

**Reason for Rejection**: Introduces performance hits due to potential heap allocations and pointer indirection; provides more flexibility than required for this high-performance core.

#### 3. Unconstrained Templates (Pre-C++20)

Using standard templates without formal interface requirements.

**Reason for Rejection**: Results in poor developer experience due to cryptic error messages and lacks the explicit interface documentation provided by Concepts.