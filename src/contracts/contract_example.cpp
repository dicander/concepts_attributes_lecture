#include <iostream>
#include <contracts> // The new C++26 header

// Calculate a year-end bonus based on salary and a performance score (0-100).
// 'r' is the variable name we assign to the return value so we can check it in the post-conditions.
int calculate_bonus(int base_salary, int performance_score)
    // --- PRECONDITIONS: Must be true BEFORE the function executes ---
    pre (base_salary > 0) 
    pre (performance_score >= 0 && performance_score <= 100)
    
    // --- POSTCONDITIONS: Must be true AFTER the function executes ---
    post (r: r >= 0)                // A bonus can never be negative
    post (r: r <= base_salary / 2)  // Company policy: Bonus cannot exceed 50% of salary
{
    // 1. Calculate the raw bonus percentage
    int bonus_percentage = performance_score / 2; 
    
    // 2. INTERNAL ASSERTION: 
    // We expect the percentage to always be between 0 and 50 at this exact line of code.
    // This replaces the old 90s assert(condition) macro.
    contract_assert(bonus_percentage >= 0 && bonus_percentage <= 50);

    // 3. Calculate final amount
    int final_bonus = (base_salary * bonus_percentage) / 100;
    
    return final_bonus;
}

int main() {
    // 1. A perfectly valid call. All contracts pass silently.
    std::cout << "Valid Bonus: $" << calculate_bonus(80000, 90) << "\n";

    // 2. BAD INPUT (Fails a Precondition)
    // If you uncomment this, the program will trigger the violation handler 
    // because the performance score is over 100.
    // calculate_bonus(80000, 150); 

    // 3. BAD LOGIC (Fails a Postcondition)
    // Let's pretend our math inside the function was bugged and it tried to 
    // return a $100,000 bonus for an $80,000 salary.
    // The 'post (r: r <= base_salary / 2)' contract would catch it right 
    // as the function tries to return, preventing the bad data from infecting 
    // the rest of your program.

    return 0;
}