/* CCF201803-3 URL映射 */

#include<bits/stdc++.h>

using namespace std;

const int N = 100;
string p[N], r[N], s;

bool match(string& s, string& t, bool flag)
{
    int lent = t.size();
    int lens = s.size();
    int ps = 0, pt = 0;
    while(ps < lens && pt < lent) {
        if(t[pt] == s[ps]) {
            ps++, pt++;
        } else {
            // 匹配<xxx>
            if(t[pt++] != '<')
                return false;
            if(flag)
                cout << ' ';

            if(t[pt] == 'i') {
                // 匹配<int>
                bool ok = false;
                while(s[ps] && isdigit(s[ps])) {
                    if(s[ps] != '0')//去掉前导零
                        ok = true;
                    if(flag && ok)
                        cout << s[ps];
                    ps++;
                }
                if(!ok)
                    return false;
                pt += 4;
            } else if(t[pt] == 's') {
                // 匹配<str>
                bool ok = false;
                while(s[ps] && s[ps] != '/') {
                    ok = true;
                    if(flag)
                        cout << s[ps];
                    ps++;
                }
                if(!ok)
                    return false;
                pt += 4;
            } else if(t[pt] == 'p') {//如果合法的话，<path>一定已经是最后一个了
                // 匹配<path>
                if(flag)
                    while(s[ps])
                        cout << s[ps++];
                return true;
            }
        }
    }

    return pt == lent && ps == lens;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> p[i] >> r[i];



    for(int i = 0; i < m; i++) {
        cin >> s;

        bool flag = true;
        for(int j = 0; flag && j < n; j++)
            if(match(s, p[j], false)) {//用了两次match，true的时候会输出
                flag = false;
                cout << r[j];
                match(s, p[j], true);
            }

        if(flag)
            cout << "404";
        cout << endl;
    }

    return 0;
}
