Question 1

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

// Transaction structure
struct Transaction {
    int id;                  // Unique transaction ID
    double amount;           // Transaction amount
    int frequency;           // Number of transactions by the user
    std::string location;    // Geographical location
    double suspiciousScore;  // Calculated suspiciousness score

    // Constructor
    Transaction(int id, double amount, int frequency, const std::string& location, double score)
        : id(id), amount(amount), frequency(frequency), location(location), suspiciousScore(score) {}

    // Overloading < operator for sorting based on suspiciousScore (higher is more suspicious)
    bool operator<(const Transaction& other) const {
        return suspiciousScore < other.suspiciousScore;
    }
};

// Function to calculate suspiciousness score based on given criteria
double calculateSuspiciousScore(double amount, int frequency, const std::string& location) {
    double locationWeight = (location == "high-risk") ? 2.0 : 1.0; // High-risk location weight multiplier
    return amount * 0.5 + frequency * 0.3 + locationWeight * 10;   // Example formula
}

int main() {
    // Sample transactions
    std::vector<Transaction> transactions = {
        {1, 1000.0, 5, "low-risk", 0.0},
        {2, 5000.0, 10, "high-risk", 0.0},
        {3, 200.0, 2, "low-risk", 0.0},
        {4, 1500.0, 8, "high-risk", 0.0},
        {5, 3000.0, 6, "low-risk", 0.0}
    };

    // Calculate suspiciousness scores for all transactions
    for (auto& transaction : transactions) {
        transaction.suspiciousScore = calculateSuspiciousScore(transaction.amount, transaction.frequency, transaction.location);
    }

    // Use a priority queue to sort transactions by suspiciousness score (highest first)
    std::priority_queue<Transaction> transactionQueue;
    for (const auto& transaction : transactions) {
        transactionQueue.push(transaction);
    }

    // Display transactions sorted by suspiciousness score
    std::cout << "High-risk transactions sorted by suspiciousness score:\n";
    while (!transactionQueue.empty()) {
        Transaction top = transactionQueue.top();
        transactionQueue.pop();
        std::cout << "Transaction ID: " << top.id
                  << ", Amount: " << top.amount
                  << ", Frequency: " << top.frequency
                  << ", Location: " << top.location
                  << ", Suspicious Score: " << top.suspiciousScore << "\n";
    }

    return 0;
}

Question 2

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

// Trade record structure
struct Trade {
    std::string timestamp;   // Timestamp of the trade
    std::string symbol;      // Stock symbol
    double price;            // Trade price
    int volume;              // Trade volume

    // Constructor
    Trade(const std::string& timestamp, const std::string& symbol, double price, int volume)
        : timestamp(timestamp), symbol(symbol), price(price), volume(volume) {}
};

// Comparator for sorting by timestamp
bool compareByTimestamp(const Trade& t1, const Trade& t2) {
    return t1.timestamp < t2.timestamp;
}

// Comparator for sorting by stock symbol
bool compareBySymbol(const Trade& t1, const Trade& t2) {
    return t1.symbol < t2.symbol;
}

// Function to group trades by volume trends
std::map<int, std::vector<Trade>> groupByVolume(const std::vector<Trade>& trades) {
    std::map<int, std::vector<Trade>> volumeGroups;
    for (const auto& trade : trades) {
        volumeGroups[trade.volume].push_back(trade);
    }
    return volumeGroups;
}

int main() {
    // Sample trade data
    std::vector<Trade> trades = {
        {"2024-12-24T10:00:01", "AAPL", 150.25, 100},
        {"2024-12-24T10:00:05", "GOOG", 2800.75, 200},
        {"2024-12-24T10:00:03", "AAPL", 151.00, 150},
        {"2024-12-24T10:00:02", "MSFT", 299.50, 100},
        {"2024-12-24T10:00:04", "GOOG", 2801.50, 150}
    };

    // Sort trades by timestamp
    std::sort(trades.begin(), trades.end(), compareByTimestamp);
    std::cout << "Trades sorted by timestamp:\n";
    for (const auto& trade : trades) {
        std::cout << "Timestamp: " << trade.timestamp
                  << ", Symbol: " << trade.symbol
                  << ", Price: " << trade.price
                  << ", Volume: " << trade.volume << "\n";
    }

    // Sort trades by stock symbol
    std::sort(trades.begin(), trades.end(), compareBySymbol);
    std::cout << "\nTrades sorted by stock symbol:\n";
    for (const auto& trade : trades) {
        std::cout << "Timestamp: " << trade.timestamp
                  << ", Symbol: " << trade.symbol
                  << ", Price: " << trade.price
                  << ", Volume: " << trade.volume << "\n";
    }

    // Group trades by volume
    auto volumeGroups = groupByVolume(trades);
    std::cout << "\nTrades grouped by volume:\n";
    for (const auto& [volume, group] : volumeGroups) {
        std::cout << "Volume: " << volume << "\n";
        for (const auto& trade : group) {
            std::cout << "    Timestamp: " << trade.timestamp
                      << ", Symbol: " << trade.symbol
                      << ", Price: " << trade.price << "\n";
        }
    }

    return 0;
}

Question 3

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

// Video catalog structure
struct Video {
    std::string title;         // Title of the video
    int views;                 // Total views
    double rating;             // User rating
    int releaseYear;           // Release year
    double relevanceScore;     // Personalized relevance score

    // Constructor
    Video(const std::string& title, int views, double rating, int releaseYear, double relevanceScore = 0.0)
        : title(title), views(views), rating(rating), releaseYear(releaseYear), relevanceScore(relevanceScore) {}
};

// Comparator for sorting by popularity (views and rating)
bool compareByPopularity(const Video& v1, const Video& v2) {
    if (v1.views == v2.views) {
        return v1.rating > v2.rating; // Break ties with higher rating
    }
    return v1.views > v2.views; // More views come first
}

// Comparator for sorting by recency (release year)
bool compareByRecency(const Video& v1, const Video& v2) {
    return v1.releaseYear > v2.releaseYear;
}

// Comparator for sorting by relevance score
bool compareByRelevance(const Video& v1, const Video& v2) {
    return v1.relevanceScore > v2.relevanceScore;
}

int main() {
    // Sample video data
    std::vector<Video> catalog = {
        {"Movie A", 1000000, 4.5, 2023},
        {"Movie B", 500000, 4.8, 2022},
        {"Show C", 2000000, 4.2, 2021},
        {"Show D", 750000, 4.7, 2023},
        {"Movie E", 300000, 4.9, 2020}
    };

    // Sort by popularity
    std::sort(catalog.begin(), catalog.end(), compareByPopularity);
    std::cout << "Videos sorted by popularity:\n";
    for (const auto& video : catalog) {
        std::cout << "Title: " << video.title
                  << ", Views: " << video.views
                  << ", Rating: " << video.rating
                  << ", Release Year: " << video.releaseYear << "\n";
    }

    // Sort by recency
    std::sort(catalog.begin(), catalog.end(), compareByRecency);
    std::cout << "\nVideos sorted by recency:\n";
    for (const auto& video : catalog) {
        std::cout << "Title: " << video.title
                  << ", Views: " << video.views
                  << ", Rating: " << video.rating
                  << ", Release Year: " << video.releaseYear << "\n";
    }

    // Assign and sort by relevance (example scores for demonstration)
    for (size_t i = 0; i < catalog.size(); ++i) {
        catalog[i].relevanceScore = 10.0 - i; // Example relevance scores
    }
    std::sort(catalog.begin(), catalog.end(), compareByRelevance);
    std::cout << "\nVideos sorted by relevance:\n";
    for (const auto& video : catalog) {
        std::cout << "Title: " << video.title
                  << ", Views: " << video.views
                  << ", Rating: " << video.rating
                  << ", Release Year: " << video.releaseYear
                  << ", Relevance Score: " << video.relevanceScore << "\n";
    }

    return 0;
}

Question 4

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

// Patient structure
struct Patient {
    std::string name;         // Patient name
    int triagePriority;       // Triage priority (higher is more critical)
    int severity;             // Severity of condition (higher is more severe)
    std::string arrivalTime;  // Arrival time

    // Constructor
    Patient(const std::string& name, int triagePriority, int severity, const std::string& arrivalTime)
        : name(name), triagePriority(triagePriority), severity(severity), arrivalTime(arrivalTime) {}

    // Comparator for priority queue
    bool operator<(const Patient& other) const {
        if (triagePriority == other.triagePriority) {
            if (severity == other.severity) {
                return arrivalTime > other.arrivalTime; // Earlier arrival gets higher priority
            }
            return severity < other.severity; // Higher severity gets higher priority
        }
        return triagePriority < other.triagePriority; // Higher triage priority gets higher priority
    }
};

int main() {
    // Priority queue for managing patients dynamically
    std::priority_queue<Patient> patientQueue;

    // Sample patient data
    patientQueue.push(Patient("Alice", 5, 8, "10:01"));
    patientQueue.push(Patient("Bob", 3, 7, "10:05"));
    patientQueue.push(Patient("Charlie", 5, 9, "10:02"));
    patientQueue.push(Patient("Diana", 4, 6, "10:03"));

    // Adding a new patient dynamically
    patientQueue.push(Patient("Eve", 6, 10, "10:06"));

    // Process patients based on priority
    std::cout << "Patients sorted by priority:\n";
    while (!patientQueue.empty()) {
        Patient top = patientQueue.top();
        patientQueue.pop();
        std::cout << "Name: " << top.name
                  << ", Triage Priority: " << top.triagePriority
                  << ", Severity: " << top.severity
                  << ", Arrival Time: " << top.arrivalTime << "\n";
    }

    return 0;
}

Question 5

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

// Ad structure
struct Ad {
    std::string advertiser;      // Advertiser name
    double bidAmount;            // Bid amount for the ad
    double engagementRate;       // Engagement rate for the ad
    double remainingBudget;      // Remaining budget for the advertiser

    // Constructor
    Ad(const std::string& advertiser, double bidAmount, double engagementRate, double remainingBudget)
        : advertiser(advertiser), bidAmount(bidAmount), engagementRate(engagementRate), remainingBudget(remainingBudget) {}

    // Comparator for priority queue
    bool operator<(const Ad& other) const {
        if (bidAmount == other.bidAmount) {
            if (engagementRate == other.engagementRate) {
                return remainingBudget < other.remainingBudget; // Higher budget gets higher priority
            }
            return engagementRate < other.engagementRate; // Higher engagement rate gets higher priority
        }
        return bidAmount < other.bidAmount; // Higher bid gets higher priority
    }
};

int main() {
    // Priority queue for managing ads dynamically
    std::priority_queue<Ad> adQueue;

    // Sample ad data
    adQueue.push(Ad("Advertiser A", 10.0, 0.8, 500.0));
    adQueue.push(Ad("Advertiser B", 15.0, 0.7, 300.0));
    adQueue.push(Ad("Advertiser C", 12.0, 0.9, 400.0));
    adQueue.push(Ad("Advertiser D", 10.0, 0.85, 600.0));

    // Adding a new ad dynamically
    adQueue.push(Ad("Advertiser E", 20.0, 0.95, 1000.0));

    // Process ads based on priority
    std::cout << "Ads sorted by priority:\n";
    while (!adQueue.empty()) {
        Ad top = adQueue.top();
        adQueue.pop();
        std::cout << "Advertiser: " << top.advertiser
                  << ", Bid Amount: " << top.bidAmount
                  << ", Engagement Rate: " << top.engagementRate
                  << ", Remaining Budget: " << top.remainingBudget << "\n";
    }

    return 0;
}
