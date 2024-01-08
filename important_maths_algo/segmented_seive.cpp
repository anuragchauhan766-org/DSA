#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void seive(int limit, vector<int> &prime)
{
    vector<bool> mark(limit + 1, true);
    mark[0] = mark[1] = false;
    for (int i = 2; i < limit; i++)
    {
        if (mark[i])
        {
            prime.push_back(i);
            cout << i << " ";
            for (int j = 2 * i; j < limit; j += i)
            {
                mark[j] = false;
            }
        }
    }
}
void segmentedseive(int n)
{
    // Compute all primes smaller than or equal
    //  to square root of n using simple sieve
    int limit = floor(sqrt(n)) + 1;
    vector<int> prime;
    prime.reserve(limit + 1);
    seive(limit, prime);
    // Divide the range [0..n-1] in different segments
    // We have chosen segment size as sqrt(n).
    int low = limit;
    int high = 2 * limit;
    // While all segments of range[0..n - 1] are not processed,
    // process one segment at a time
    while (low < n)
    {
        if (high >= n)
            high = n;
        vector<bool> mark(limit + 1, true);
        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (int i = 0; i < prime.size(); i++)
        {
            int low_mul = (low / prime[i]) * prime[i];
            if (low_mul < low)
                low_mul += prime[i];
            /* Mark multiples of prime[i] in [low..high]:
                          We are marking j - low for j, i.e. each number
                          in range [low, high] is mapped to [0, high-low]
                          so if range is [50, 100] marking 50 corresponds
                          to marking 0, marking 51 corresponds to 1 and
                          so on. In this way we need to allocate space only
                          for range */
            for (int j = low_mul; j < high; j += prime[i])
            {
                mark[j - low] = false;
            }
        }
        // Numbers which are not marked as false are prime
        for (int i = low; i < high; i++)
        {
            if (mark[i - low])
                cout << i << " ";
        }
        // Update low and high for next segment
        low = low + limit;
        high = high + limit;
    }
}
int main()
{

    segmentedseive(30);

    return 0;
}