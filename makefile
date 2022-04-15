all : solve_dup rand

solve_dup : solve_dup.cpp; c++ solve_dup.cpp -o solve_dup
rand : rand.cpp; c++ rand.cpp -o rand
    
    
