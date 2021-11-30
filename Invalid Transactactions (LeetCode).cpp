class transaction {
public:
    string name;
    int time;
    int amount;
    string city;

    // Parametrised Constructor
    transaction(string name, int time, int amount, string city)
    {
        this->name = name;
        this->time = time;
        this->amount = amount;
        this->city = city;
    }
};

class Solution {
public:

    vector<string> invalidTransactions(vector<string>& transactions) {

        // Vector of class 'transaction' to store the input effeciently
        vector<transaction> input;
        int n = transactions.size();
        vector<bool> valid(n, true);

        //extracting information from string
        for (int i = 0; i < n; i++)
        {
            string curr = transactions[i];
            string name = "", time = "", amount = "", city = "";
            int j = 0;

            while (curr[j] != ',')
                name += curr[j++];

            j++;

            while (curr[j] != ',')
                time += curr[j++];

            j++;

            while (curr[j] != ',')
                amount += curr[j++];

            j++;

            while (j < curr.size())
                city += curr[j++];

            // Creating a object 't' of class transaction
            transaction t(name, stoi(time), stoi(amount), city);
            input.push_back(t);
        }

        //first check : amount > 1000
        for (int i = 0; i < input.size(); i++)
            if (input[i].amount > 1000)
                valid[i] = false;

        //second check, pair wise
        for (int i = 0; i < (input.size()); i++)
        {
            for (int j = 0; j < input.size(); j++)
            {
                if (i == j)
                    continue;

                int timediff = abs(input[j].time - input[i].time);
                if (timediff <= 60)
                {
                    if ((input[j].name == input[i].name) && (input[j].city != input[i].city))
                        valid[i] = false, valid[j] = false;
                }
            }
        }

        //Insert Invalid transactions to final answer
        vector<string> ans;
        for (int i = 0; i < input.size(); i++)
            if (!valid[i])
                ans.push_back(transactions[i]);

        return ans;
    }
};
