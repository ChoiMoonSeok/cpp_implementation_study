#include <iostream>
#include <vector>
#include <random>

std::vector<int> merge_sort(std::vector<int> div_con)
{

    if (div_con.size() > 1)
    {
        // divide

        // 전체 벡터의 길이가 3인 경우
        if (div_con.size() == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3 - i; j++)
                {
                    if (div_con[i] > div_con[i + j])
                    {
                        int tmp = div_con[i];
                        div_con[i] = div_con[i + j];
                        div_con[i + j] = tmp;
                    }
                }
            }

            return div_con;
        }

        std::vector<int> div_con_low(div_con.begin(), div_con.begin() + div_con.size() / 2);
        div_con_low = merge_sort(div_con_low);
        std::vector<int> div_con_high(div_con.end() - div_con.size() / 2, div_con.end());
        div_con_high = merge_sort(div_con_high);

        // conquer

        std::vector<int> conquer;
        while (true)
        {
            if (div_con_low.size() > 0)
            {
                if (div_con_high.size() > 0)
                {

                    if (div_con_low[0] < div_con_high[0])
                    {
                        conquer.push_back(div_con_low[0]);
                        div_con_low.erase(div_con_low.begin());
                    }
                    else
                    {
                        conquer.push_back(div_con_high[0]);
                        div_con_high.erase(div_con_high.begin());
                    }
                }
                else
                {
                    conquer.push_back(div_con_low[0]);
                    div_con_low.erase(div_con_low.begin());
                }
            }
            else
            {
                if (div_con_high.size() > 0)
                {
                    conquer.push_back(div_con_high[0]);
                    div_con_high.erase(div_con_high.begin());
                }
                else
                    break;
            }
        }
        return conquer;
    }
    else
    {
        return div_con;
    }
}