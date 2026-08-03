#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int>result{};
    result.reserve(student_scores.size());
    for (auto score:student_scores){
        score=static_cast<int>(score);
        result.emplace_back(score);
        
    }
    return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(const std::vector<int> &student_scores) {
    int failed_students{0};
    for (auto score2:student_scores){
        if (score2<=40){
            ++failed_students;
        }
    }
    return failed_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    std::array<int, 4> new_letters{41};
    
    for (int i = 1; i <= 3; ++i) {
        int score = ((highest_score - 40.0) / 4.0) * i + 41;
        new_letters[i] = score;
    }    
    
    return new_letters;
}



std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string>ranked_vector{};
    for (size_t i=0;i<student_names.size();++i) { 
        ranked_vector.emplace_back(std::to_string(i+1)+". "+student_names[i]+": "+std::to_string(student_scores[i]));
    }
    return ranked_vector;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,std::vector<std::string> student_names) {
    for (size_t i=0;i<student_scores.size();++i){
         if (student_scores[i]==100){
             return student_names[i];
         }
    }
    return "";
}
