#include <iostream>
#include <fstream>

class FileReader {
private:
    std::string filename;
    int characterCounts[128];  // Assuming ASCII characters

public:
    // Constructor
    FileReader(const std::string& fname) : filename(fname) {
        for (int i = 0; i < 128; i++) {
            characterCounts[i] = 0;
        }
    }

    // Destructor
    ~FileReader() {
        displayCharacterCounts();
    }

    // Read the file and update character counts
    void readFile() {
        std::ifstream file(filename);

        // Check if the file opened successfully
        if (!file.is_open()) {
            std::cout << "Error opening file: " << filename << std::endl;
            return;
        }

        char ch;
        while (file.get(ch)) {
            characterCounts[ch]++;
        }

        file.close();
    }

private:
    // Display the character counts
    void displayCharacterCounts() const {
        std::cout << "Character Counts for file: " << filename << std::endl;
        for (int i = 0; i < 128; i++) {
            if (characterCounts[i] > 0) {
                std::cout << static_cast<char>(i) << ": " << characterCounts[i] << std::endl;
            }
        }
    }
};

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    FileReader reader(filename);  // Create FileReader object with the provided filename
    reader.readFile();  // Read the file and update character counts

    return 0;
}
