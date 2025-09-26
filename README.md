# 📅 Lesson Conflict Detector in C

This project is a **C implementation of a scheduling conflict detection algorithm**.  
It takes lesson start times and durations as input, calculates overlapping lessons, and outputs a conflict matrix showing which lessons clash with each other.

---

## 📌 Features
- Reads **N lessons** with:
  - Start time
  - Duration
- Calculates each lesson’s **end time**.
- Detects **overlapping (conflicting) lessons**.
- Stores conflicts in an adjacency matrix `M`.
- Prints conflict pairs in a clear format.

---

## ⚙️ How It Works
1. User enters:
   - Start time and duration for each lesson.
2. Program:
   - Computes each lesson’s end time.
   - Checks for overlaps with other lessons.
   - Updates the conflict matrix `M[i][j] = 1` if lesson `i` conflicts with lesson `j`.
3. Results are displayed as **pairs of conflicting lessons**.

---

## 🚀 Compilation & Execution

### Compile
```bash
gcc conflict_detector.c -o conflict_detector
