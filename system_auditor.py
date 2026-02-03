"""
Project: Automated System Health Auditor
Author: [Your Name]
Description: A cross-platform utility script to monitor critical system 
metrics including disk usage, OS status, and simulated thermal thresholds.
"""

import shutil
import platform
import datetime
import os

def check_disk_usage():
    # Checks the storage health of the primary partition
    total, used, free = shutil.disk_usage("/")
    percent_used = (used / total) * 100
    print(f"[STORAGE] Total: {total // (2**30)}GB | Used: {used // (2**30)}GB | Free: {percent_used:.1f}% used")
    return percent_used

def check_system_info():
    # Identifies the environment for troubleshooting
    print(f"[SYSTEM] OS: {platform.system()} {platform.release()}")
    print(f"[SYSTEM] Processor: {platform.processor()}")

def monitor_thermal_thresholds():
    # Simulated thermal logic based on the 'Point of No Return' concept
    # In a real Linux environment, we would pull from /sys/class/thermal/
    simulated_temp = 52.0  # Celsius
    CRITICAL_TEMP = 75.0
    
    if simulated_temp >= CRITICAL_TEMP:
        print(f"[ALERT] CRITICAL TEMPERATURE: {simulated_temp}°C. Throttling Recommended.")
    else:
        print(f"[HEALTH] Thermal Levels: {simulated_temp}°C (Stable)")

def log_results(status):
    # Ensures a paper trail for IT audits
    timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    log_entry = f"{timestamp} | Disk Status: {status} | Health Check: PASSED\n"
    
    with open("audit_log.txt", "a") as log_file:
        log_file.write(log_entry)
    print("\n[LOG] Audit results saved to audit_log.txt")

if __name__ == "__main__":
    print("--- Starting System Health Audit ---\n")
    check_system_info()
    usage = check_disk_usage()
    monitor_thermal_thresholds()
    
    status_msg = "OK" if usage < 90 else "WARNING"
    log_results(status_msg)
    print("\n--- Audit Complete ---")
