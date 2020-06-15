
namespace NEAT{
    template<typename T>
    T diff(const T &first, const T &second)
    {
        if(first > second)
            return first-second;
        else
            return second-first;
        
    }

    template<typename T>
    T larger(const T &first, const T &second)
    {
        if (first > second)
            return first;
        else
            return second;
    }
}