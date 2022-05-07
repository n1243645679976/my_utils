all : solve_dup rand sscanf round

solve_dup : solve_dup.cpp; c++ solve_dup.cpp -o solve_dup
rand : rand.cpp; c++ rand.cpp -o rand
sscanf : sscanf.cpp make_sscanf_cpp.sh; bash make_sscanf_cpp.sh; c++ sscanf.cpp -o sscanf;
round : round.cpp; c++ round.cpp -o round
