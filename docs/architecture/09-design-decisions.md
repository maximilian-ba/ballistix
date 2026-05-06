This section summarizes the most critical architectural decisions. For a complete chronological history of all decisions, please refer to the [ADR Log](adr/index.md).

## 9.1 Core Abstraction & Performance
We have decided to prioritize compile-time performance over runtime flexibility for the simulation's core components (Solvers and Forces).

*   **Decision:** Use Static Polymorphism (Templates + Concepts).
*   **Rationale:** Eliminates vtable overhead and enables vertical inlining.
*   **Details:** See [ADR 0001: Core Abstraction](adr/0001-core-abstraction.md).

## 9.2 Time-Stepping & Simulation Stability

We have decided to decouple the simulation clock from the library core to support diverse host environments (game engines vs. standalone tools).

*   **Decision:** Externalize Delta Time ($dt$) management.
*   **Rationale:** Provides maximum integration flexibility and avoids "Spiral of Death" scenarios within the library itself.
*   **Details:** See [ADR 0002: Time-Stepping Strategy](adr/0002-time-stepping-strategy.md).