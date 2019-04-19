int min_changes(const vector<int>& vec, int target)
{
    if(target == 0) return 0;
    int m_c = numeric_limits<int>::max();
    for(auto e: vec){
        if(target-e >= 0)
            m_c = min(m_c, 1+min_changes(vec, target-e));
    }
    return m_c;
}
