/* * Project: Interrupt-Driven Hardware State Machine
 * Author: [Your Name]
 * Description: Implements a deterministic state machine to manage 
 * hardware transitions (e.g., LED or Actuator control) using 
 * non-blocking logic. 
 */

#include <stdio.h>

// Define system states for a physical-to-digital handshake
typedef enum {
    SYS_IDLE,        // System waiting for input
    SYS_PENDING,     // Intent recorded, checking sensors
    SYS_ACTIVE,      // Physical action in progress
    SYS_EMERGENCY    // Fault detected or power-loss recovery mode
} SystemState;

SystemState currentState = SYS_IDLE;

// Simulated Hardware Interrupt Service Routine (ISR)
// In a real STM32/AVR, this would be triggered by a physical GPIO pin
void on_button_press_interrupt() {
    printf("\n[INTERRUPT] Hardware Signal Detected. Transitioning state...\n");
    
    if (currentState == SYS_IDLE) {
        currentState = SYS_PENDING;
    } else if (currentState == SYS_PENDING) {
        currentState = SYS_ACTIVE;
    } else {
        currentState = SYS_IDLE; // Reset to IDLE
    }
}

// Deterministic Logic: What the hardware actually DOES in each state
void run_state_logic() {
    switch(currentState) {
        case SYS_IDLE:
            printf("Current State: IDLE    | Power: Low-Power Mode (Wait for Input) \r");
            break;
        case SYS_PENDING:
            printf("Current State: PENDING | Action: Verifying Integrity Handshake...\r");
            break;
        case SYS_ACTIVE:
            printf("Current State: ACTIVE  | Action: Executing Physical Change      \r");
            break;
        case SYS_EMERGENCY:
            printf("Current State: ERROR   | Action: Executing Safe Shutdown        \r");
            break;
    }
}

int main() {
    printf("--- Embedded Systems State Machine Initialized ---\n");
    printf("Logic Type: Deterministic / Interrupt-Driven\n\n");

    // Simulating a real-world loop
    for (int i = 0; i < 6; i++) {
        run_state_logic();
        
        // Simulate a button press happening at specific intervals
        if (i == 1 || i == 3 || i == 5) {
            on_button_press_interrupt();
        }
    }

    printf("\n\nSystem Simulation Complete.");
    return 0;
}
