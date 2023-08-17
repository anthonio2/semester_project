#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SearchResult {
public:
    std::string title;
    std::string content;
};

class SearchEngine {
private:
    struct IndexedData {
        std::string title;
        std::string content;
    };

    std::vector<IndexedData> data;

public:
    void addData(const std::string& title, const std::string& content) {
        data.push_back({title, content});
    }

    std::vector<SearchResult> search(const std::string& query) {
        std::vector<SearchResult> results;

        for (const IndexedData& item : data) {
            if (item.title.find(query) != std::string::npos ||
                item.content.find(query) != std::string::npos) {
                SearchResult result;
                result.title = item.title;
                result.content = item.content;
                results.push_back(result);
            }
        }

        return results;
    }
};

int main() {
    SearchEngine searchEngine;

    searchEngine.addData("Introduction to C++", "Learn the basics of C++ programming.");
    searchEngine.addData("Data Structures", "Explore different data structures in C++.");

    std::string query;
    std::cout << "Enter your search query: ";
    std::getline(std::cin, query);

    std::vector<SearchResult> results = searchEngine.search(query);

    if (results.empty()) {
        std::cout << "No results found." << std::endl;
    } else {
        std::cout << "Search Results:" << std::endl;
        for (const SearchResult& result : results) {
            std::cout << "Title: " << result.title << std::endl;
            std::cout << "Content: " << result.content << std::endl;
            std::cout << "------------------------------" << std::endl;
        }
    }

    return 0;
}
