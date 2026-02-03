# Embedded-C-Labs
1. Project Overview: Deterministic State Machine
This project demonstrates a robust approach to controlling hardware states using the C programming language. It is designed to bridge the gap between a physical user input (like a button press) and a digital system state, ensuring that transitions are predictable and non-blocking.

2. Key Technical Configurations
Architecture: Finite State Machine (FSM).

Logic Type: Interrupt-Driven (Simulated). Unlike "Polling" (which wastes CPU cycles), this code uses an interrupt-style structure to change states only when a signal is detected.

Safety Features: * IDLE State: Keeps the system in a low-power "listening" mode.

PENDING State: Acts as a buffer to verify data integrity before the physical action (ACTIVE) is triggered.

3. How to Compile & Run
To verify the logic on any standard computer (Linux, macOS, or Windows):

Compiler: Requires a standard C compiler (GCC or Clang).

Command: ```bash gcc state_machine.c -o state_machine ./state_machine


4. "Handshake" Logic Explanation
The system follows a strict IDLE -> PENDING -> ACTIVE path. If power were lost during the PENDING state, the system is configured to reboot into a "Verification" mode to check if the hardware and the database are still in sync—a critical requirement for the Physical-to-Digital handshake mentioned in my technical assessments.

## Automated System Health Auditor (Python)
Purpose: To automate the monitoring of hardware resources and prevent system failure due to storage exhaustion or thermal overheating.

Features:

Disk Telemetry: Monitors partition health and calculates usage percentages.

Thermal Logic: Implements threshold-based alerting (Simulated) to demonstrate knowledge of hardware protection.

Persistent Logging: Automatically generates an audit_log.txt file, providing a historical record for IT incident reports.

How to Run: python system_auditor.py
