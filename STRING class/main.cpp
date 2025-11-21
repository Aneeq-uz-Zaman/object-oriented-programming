#include <iostream>
using namespace std;

class String
{
private:
    char *str;
    int length;

    // Helper: Calculate length of C-string
    int getLength(const char *s) const
    {
        int len = 0;
        while (s[len] != '\0')
        {
            len++;
        }
        return len;
    }

    // Helper: Copy string
    void copyStr(char *dest, const char *src) const
    {
        int i = 0;
        while (src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    // Helper: Compare strings
    int compareStr(const char *a, const char *b) const
    {
        int i = 0;
        while (a[i] != '\0' && b[i] != '\0')
        {
            if (a[i] != b[i])
                return a[i] - b[i];
            i++;
        }
        return a[i] - b[i];
    }

    // Helper: Concatenate strings
    void concatStr(char *dest, const char *src) const
    {
        int i = 0;
        while (dest[i] != '\0')
            i++;

        int j = 0;
        while (src[j] != '\0')
        {
            dest[i] = src[j];
            i++;
            j++;
        }
        dest[i] = '\0';
    }

public:
    // Default constructor
    String()
    {
        str = new char[1];
        str[0] = '\0';
        length = 0;
    }

    // Parameterized constructor
    String(const char *s)
    {
        length = getLength(s);
        str = new char[length + 1];
        copyStr(str, s);
    }

    // Copy constructor
    String(const String &s)
    {
        length = s.length;
        str = new char[length + 1];
        copyStr(str, s.str);
    }

    // Destructor
    ~String()
    {
        delete[] str;
    }

    // Assignment operator =
    String &operator=(const String &s)
    {
        if (this != &s)
        {
            delete[] str;
            length = s.length;
            str = new char[length + 1];
            copyStr(str, s.str);
        }
        return *this;
    }

    // Concatenation operator +
    String operator+(const String &s) const
    {
        cout << "Concatenating strings..." << endl;
        String r;
        r.length = length + s.length;
        r.str = new char[r.length + 1];
        concatStr(r.str, str);
        concatStr(r.str, s.str);
        return r;
    }

    // Equality operator ==
    bool operator==(const String &s) const
    {
        return compareStr(str, s.str) == 0;
    }

    // Not Equal !=
    bool operator!=(const String &s) const
    {
        return !(*this == s);
    }

    // Index operator []
    char &operator[](int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Index out of bounds!" << endl;
            exit(1);
        }
        return str[index];
    }

    // Output operator <<
    friend ostream &operator<<(ostream &out, const String &s)
    {
        out << s.str;
        return out;
    }

    // Input operator >>
    friend istream &operator>>(istream &in, String &s)
    {
        char temp[1000];
        in >> temp;
        s = String(temp);
        return in;
    }

    int getLength() const
    {
        return length;
    }

    const char *getString() const
    {
        return str;
    }
};

// Test main
int main()
{
    String s1("Hello");
    String s2("World");
    String s3;

    cout << "Enter a string: ";
    cin >> s3;

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    String s4 = s1 + s2;
    cout << "s1 + s2: " << s4 << endl;

    if (s1 == s2)
        cout << "s1 and s2 are equal." << endl;
    else
        cout << "s1 and s2 are not equal." << endl;

    cout << "Character at index 1 in s1: " << s1[1] << endl;

    return 0;
}
