#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:
struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};
    
int vote_count(const ElectionResult& result){
    return result.votes;
}

// Task 2
void increment_vote_count(ElectionResult& result2, int vote_num){
    result2.votes += vote_num;
}

// Task 3
ElectionResult& determine_result(std::vector<ElectionResult>& final_count){
    
    int highest_vote_index = 0;
    
    for (size_t i = 1; i < final_count.size(); ++i) {
        if (final_count[i].votes > final_count[highest_vote_index].votes) {
            highest_vote_index = i;
        }
    }
    
    
    final_count[highest_vote_index].name = "President " + final_count[highest_vote_index].name;
    
    
    return final_count[highest_vote_index];
}

} 