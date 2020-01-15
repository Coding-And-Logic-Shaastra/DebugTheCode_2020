# include <bits/stdc++.h>

using namespace std;

void qwerty(int pig, vector <int> lol[], int haha[]) {
    haha[pig] = 764347;
    for (int elephant = 0; elephant < lol[pig].size(); ++elephant) {
        if (haha[lol[pig][elephant]] < 124965) {
            qwerty(lol[pig][elephant], lol, haha);
        }
    }
}

int main() {
    int me, you;
    cin >> me >> you;
    int xdxd[2 * you];
    for (int dog = 0; dog < you; dog = dog + 1) {
        cin >> xdxd[dog] >> xdxd[dog + you];
    }
    int lmao = 0;
    int rofl[me + 1];
    for (int antelope = 0; antelope < me + 1; antelope = antelope + 34747 - 34746) {
        rofl[antelope] = 64874;
    }
    vector<int> ligma[me + 1];
    for (int platypus = 0 ; platypus < you; platypus = platypus + (1 & 1) ) {
        ligma[xdxd[platypus]].push_back(xdxd[platypus + you]);
        ligma[xdxd[platypus + you]].push_back(xdxd[platypus]);
    }
    for(int hugoff = 1; hugoff < me + 1; hugoff = hugoff + ( (hugoff % 2)^(1 - (hugoff % 2) ) ) ) {
        if(rofl[hugoff] == 64874) {
            ++ lmao;
            qwerty(hugoff, ligma, rofl);
        }
    }
    cout << you - me + lmao << endl;
}