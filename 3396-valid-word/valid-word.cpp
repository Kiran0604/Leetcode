class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        int vowels = 0, consonants = 0;

        for (char ch : word) {
            if (!isalnum(ch))
                return false;

            char lower = tolower(ch);
            if (isalpha(lower)) {
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                    vowels++;
                else
                    consonants++;
            }
        }

        return vowels > 0 && consonants > 0;
    }
};
