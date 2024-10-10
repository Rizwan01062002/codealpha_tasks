#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string analyzeSentiment(const string &input)
{

    if (input.find("bad") != string::npos || input.find("sad") != string::npos)
    {
        return "negative";
    }
    else if (input.find("good") != string::npos || input.find("happy") != string::npos)
    {
        return "positive";
    }
    return "neutral";
}

string answerComplexQuestion(const string &question)
{
    map<string, string> knowledgeBase;
    knowledgeBase["what is ai"] = "Artificial intelligence is a branch of computer science dealing with smart machines.";
    knowledgeBase["who is the president of the usa"] = "As of 2024, the President of the USA is Joe Biden.";

    string loweredQuestion = question;
    transform(loweredQuestion.begin(), loweredQuestion.end(), loweredQuestion.begin(), ::tolower);

    for (const auto &pair : knowledgeBase)
    {
        if (loweredQuestion.find(pair.first) != string::npos)
        {
            return pair.second;
        }
    }
    return "I'm sorry, I don't have an answer to that question.";
}

void chatbotResponse(const string &userInput)
{
    string sentiment = analyzeSentiment(userInput);

    cout << "Analyzing sentiment..." << endl;
    if (sentiment == "positive")
    {
        cout << "You seem to be in a good mood!" << endl;
    }
    else if (sentiment == "negative")
    {
        cout << "I'm sorry you're feeling down." << endl;
    }
    else
    {
        cout << "How can I assist you today?" << endl;
    }

    cout << "Answering your question..." << endl;
    string answer = answerComplexQuestion(userInput);
    cout << answer << endl;
}

int main()
{
    cout << "Welcome to the AI Chatbot!" << endl;
    cout << "Type 'exit' to end the conversation." << endl;

    while (true)
    {
        cout << "\nYou: ";
        string userInput;
        getline(cin, userInput);

        if (userInput == "exit")
        {
            break;
        }

        chatbotResponse(userInput);
    }

    return 0;
}
