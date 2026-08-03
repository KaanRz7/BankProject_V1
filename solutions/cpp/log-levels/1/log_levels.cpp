#include <string>

namespace log_line {

// Mesajı tek satırda kesip döndür
std::string message(std::string line) {
    return line.substr(line.find(": ") + 2);
}

// Log seviyesini tek satırda kesip döndür
std::string log_level(std::string line) {
    return line.substr(line.find('[') + 1, line.find(']') - line.find('[') - 1);
}

// İkisini birleştir, parantezli format yap
std::string reformat(std::string line) {
    return message(line) + " (" + log_level(line) + ")";
}

}  // namespace log_line