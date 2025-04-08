class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0);

        // Multiply each digit and store the result
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Convert result vector to string
        string product;
        for (int num : result) {
            if (!(product.empty() && num == 0)) { // Skip leading zeros
                product.push_back(num + '0');
            }
        }

        return product.empty() ? "0" : product;
    }
};
