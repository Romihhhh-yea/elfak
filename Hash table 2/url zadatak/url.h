#include <deque>

using namespace std;

class BrowserHistory
{
private:
    deque<char*> history;
    int k;

public:
    BrowserHistory(int k)
    {
        this->k = k;
    }

    void AddToHistory(char* url)
    {
        if (history.size() == k)
            history.pop_front();

        history.push_back(url);
    }

    char* Back()
    {
        if (history.empty())
            return NULL;

        return history.back();
    }
};