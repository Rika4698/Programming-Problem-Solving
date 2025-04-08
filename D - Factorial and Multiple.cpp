#include <bits/stdc++.h>

using namespace std;

map<long long, int>primeFactor(long long k)
{
    map<long long, int>factor;
    for(long long i=2; i*i<=k; i++)
    {
        while(k % i == 0)
        {
            factor[i]++;
            k = k/i;
        }
    }
    if(k>1) factor[k]++;
    return factor;

}


long long countPrimeFactorial(long long N, long long p)
{
    long long count = 0, power = p;
    while(N/power > 0)
    {
        count = count  + N/power;
        power = power * p;
    }
    return count;
}

long long minimumN(long long k)
{
    map<long long, int>factors = primeFactor(k);
    long long left = 2, right = k, result = k;
    while(left <= right)
    {
        long long mid = left + (right - left)/2;
        bool valid = true;

        for(auto[prime,power]:factors)
        {
            if(countPrimeFactorial(mid, prime)<power)
            {
                valid=false;
                break;
            }
        }
        if(valid)
        {
            result = mid ;
            right = mid - 1;

        }
        else{
            left = mid +1;
        }
    }
    return result;
}

int main()
{
    long long k;
    cin>>k;
    cout<<minimumN(k)<<"\n";

    return 0;
}

/*map<long long, int> primeFactor(long long K) {
    map<long long, int> factor;
    for (long long i = 2; i * i <= K; i++) {
        while (K % i == 0) {
            factor[i]++;
            K /= i;
        }
    }
    if (K > 1) factor[K]++;
    return factor;
}


long long countPrimeFactorial(long long N, long long p) {
    long long count = 0, power = p;
    while (N / power > 0) {
        count += N / power;
        power *= p;
    }
    return count;
}


long long minimumN(long long K) {
    map<long long, int> factors = primeFactor(K);
    long long left = 2, right = K, output = K;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        bool valid = true;

        for (auto [prime, power] : factors) {
            if (countPrimeFactorial(mid, prime) < power) {
                valid = false;
                break;
            }
        }

        if (valid) {
            output = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return output;
}

int main() {
    long long K;
    cin >> K;
    cout << minimumN(K) << "\n";
    return 0;
}*/

