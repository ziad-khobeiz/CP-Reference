class node
{
public:
    int vis;
    node *child[26];
    node()
    {
        vis = 0;
        for(int i=0; i<26; i++)
            child[i] = 0;
    }
};

node *root = new node;

void add(string s)
{
    node *tmp = root;
    for(int i=0; i<s.size(); i++)
    {
        if(tmp->child[s[i]-'a'] == 0)
            tmp->child[s[i]-'a'] = new node();
        tmp = tmp->child[s[i]-'a'];
        tmp->vis++;
    }
}

int get(string s)
{
    node *tmp = root;
    for(int i=0; i<s.size(); i++)
    {
        if(tmp->child[s[i]-'a'] == 0)
            return 0;
        tmp = tmp->child[s[i]-'a'];
    }
    return tmp->vis;
}
