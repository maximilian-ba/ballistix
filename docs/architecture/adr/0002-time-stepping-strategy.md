# ADR 0002: Time-Stepping Strategy

**Status:** Accepted  
**Date:** 2026-05-06

## Context

We need to support different runtime environments (standalone simulations vs. game engine integrations). Some require a strict fixed time-step for reproducibility, while others require a variable time-step to match frame rates.


## Decision

The computational core will not manage its own internal clock. Instead, the delta_time ($dt$) must be passed as a parameter to the integration functions.


## Consequences

#### Positive

* Maximum integration flexibility for the consumer.

#### Neutral

* The user is responsible for implementing any "Accumulator" logic (e.g., Fix Your Timestep!) outside of the core library.

#### Negative

* No built-in protection against "Spiral of Death" scenarios if the user provides inconsistent $dt$ values.


## Alternatives

#### 1. Internal Fixed Timestep (The "Accumulator" Pattern)

The library manages its own clock. You give it the total elapsed time, and it runs as many $0.01s$ steps as needed.

**Reason for Rejection**: This is too "heavy" for a library. It forces a specific update logic on the user and makes it harder to sync with external engines that might have their own fixed-step loops.

#### 2. Strict Variable $dt$ (No Tracing)

Just move the bullet based on whatever $dt$ comes in, without checking the path between points.

**Reason for Rejection**: A fast bullet could pass through a thin target if the frame rate drops. Since this is a ballistics library, missing a hit due to frame rate is an unacceptable failure.

#### 3. Analytical Solution (The "Physics Formula" Path)

Instead of stepping through time (numerical integration), use a single math formula to calculate the exact position at time $t$.

**Reason for Rejection**:  This only works for simple gravity ($y = \frac{1}{2}gt^2$). Once you add complex air drag (which changes based on velocity), there is no simple formula. You **must** use a solver like Euler or RK4 to get an accurate result.