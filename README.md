# Ballistix

![License](https://img.shields.io/github/license/maximilian-ba/ballistix)
![C++ Version](https://img.shields.io/badge/C%2B%2B-20-blue)

> **Ballistix** is a high-performance, modern C++20 header-only engine designed for the precise simulation of the entire ballistic chain — from the initial launch, through flight in the atmosphere, to terminal impact.


## Architecture

The engine is structured into four specialized domains to ensure a clear separation of physical phases:

* **Core:** The backbone of the engine, providing a shared mathematical foundation. It features a high-performance, templated math library, physical constants, and zero-overhead unit conversion utilities.
* **Internal (Launch):** Energy transfer and acceleration dynamics within the propulsion system.
* **External (Flight):** Trajectory calculation, atmospheric models, and aerodynamic drag.
* **Terminal (Impact):** Kinetic energy transfer, penetration depth, and interaction with the target medium.


## Design Goals & Tech Stack

Instead of a generic feature list, **Ballistix** is built against strict engineering requirements to ensure its suitability for professional environments:

* **Performance-First:** A header-only, exception-free core designed for real-time applications and low-latency simulations.
* **Flexibility:** Fully templated math layers allow for selectable precision (`float` vs. `double`) depending on the use case.
* **Determinism:** Built for reproducibility, ensuring identical results across simulation runs.
* **Modern Standards:** Leveraging **C++20 Concepts** for robust APIs and **TDD (GoogleTest)** for mathematical precision.
* **Professional Workflow:** Development is tracked via **Jira** to maintain a structured and transparent software lifecycle.


## Getting Started

### Prerequisites

* **C++20** compatible compiler (GCC 10+, Clang 10+, MSVC 19.29+)
* **CMake 3.15+**

### Installation

As a **header-only** library, integration is straightforward. Copy the `include/` directory into your project and you are ready to go.

```cpp
#include <Ballistix/Ballistix.hpp>
```

### Verification (Testing)

To ensure the mathematical precision of the engine on your specific architecture, run the test suite:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build
```

### Quick Start

> **Status:** The API is currently being finalized. Once the `Ballistix-External` module is stable, a minimal launch simulation example will be provided here.


## Usage / Documentation

> **Info:** Structured web documentation is currently under development and will be linked here shortly.


## License

This project is licensed under the [GPL-3.0](LICENSE) - see the [LICENSE](LICENSE) file for details.


## Contributing

While **Ballistix** is primarily a portfolio project to demonstrate high-performance C++ engineering, contributions, technical discussions, and feedback are highly welcome.

If you'd like to discuss technical aspects, propose a feature, or report an issue, please check the [contributing guidelines](docs/CONTRIBUTING.md).
