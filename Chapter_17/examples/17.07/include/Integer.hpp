class Integer
{
public:
    Integer(int = 0);
    ~Integer();
    void setInteger(int);
    int getInteger() const;

private:
    int value;
};
