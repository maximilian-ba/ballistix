# Contributing to Ballistix

First of all, thank you for taking the time to review or contribute to this project! 

> **Ballistix** is a portfolio project focused on high-performance C++ engineering. While I am the primary maintainer, I highly value technical discussions, bug reports, and feedback.


## How to Contribute

### 1. Technical Discussions & Feedback
If you have suggestions regarding the mathematical models or performance optimizations:
* Open an **Issue** to discuss your ideas.
* Use the "technical-discussion" label if applicable.


### 2. Reporting Issues

If you find a bug or a physical inconsistency:

* Search the [Issue Tracker](https://github.com/maximilian-ba/ballistix/issues) for existing reports.
* If it's new, open a detailed issue including:
    * Environment (Compiler, OS, Architecture)
    * Steps to reproduce
    * Expected vs. actual behavior


### 3. Development Workflow

If you wish to submit code:

1. **Fork** the repository and create your **Feature Branch** from `main`.
2. Ensure your code follows the project's **Coding Standards** (see below).
3. Every new feature must be accompanied by **GoogleTest** units.
4. Submit a **Pull Request** with a clear description of the changes.


## Engineering Standards

To maintain the high-performance nature of this engine, please adhere to these guidelines:


### C++ Standards & Performance

* **Language:** C++20
* **Templates:** Use **Concepts** to constrain template parameters and improve compiler diagnostics.
* **Efficiency:** Avoid runtime exceptions in the core simulation loop. Prefer std::optional, custom result types, or assertions for internal logic checks to keep the simulation loop exception-free.
* **Zero-Overhead:** Ensure that utilities (like unit conversions) are optimized away at compile-time using `constexpr`.


### Mathematical Precision

* All calculations should be unit-agnostic or strictly use SI units via the core conversion utilities.
* Any new physical model should reference a scientific source or a specific ballistic formula in the PR description.


### Testing Requirement

* **Test-Driven Development:** Every new feature or bug fix must be accompanied by corresponding unit tests.
* Ballistix aims for high test coverage across all modules to ensure mathematical and functional integrity.
* Run the suite before submitting:

```bash
cmake --build build --target BallistixTests
ctest --test-dir build
```


### Project Management

Ballistix utilizes **Jira** to track the roadmap and active tasks. For insights into long-term planning or the current flow status, please refer to the links provided in the main README.

Thank you for helping make Ballistix a more precise and efficient engine!