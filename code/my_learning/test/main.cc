#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


const int MAXN = 1e6 + 7;
struct Node{

    Node *ls = NULL , *rs = NULL;
    // 本数据出现次数（为 0 代表已删除）
    int wn = 0 ;
    // 已删除节点不计的子树大小（每个节点记 1 次） 有用的节点数量
    int sd = 0;
    //以本节点为根的子树大小（每个节点记 wn[k] 次） 用于计算次序
    int sz = 0;
    //当前节点子树大小  所有节点数量
    int tree_size = 0;
    int res;
    void init(){
        tree_size = 0;
        wn = 0;
        sd = 0;
        sz = 0;
    }
}allNode[MAXN];

queue<Node*> freeNode;
double alpha = 0.75;


Node zero;


void Calc(Node *k) {
    // 重新计算以 k 为根的子树大小
    if(k == &zero){
        return ;
    }
    Node *ls = k ->ls, *rs = k->rs;
    k->tree_size = ls->tree_size + rs->tree_size  + 1 ;
    k->sz = ls->sz + rs->sz  + k->wn;
    k->sd = ls->sd + rs -> sd + (k->wn != 0);
}
Node * getFreeNode(int res){
    Node *node = freeNode.front();
    freeNode.pop();
    node -> init();
    node -> res = res;
    node->ls = &zero;
    node->rs = &zero;
    node->wn = 1;
    Calc(node);
    return node;
}

void Rbu_Flatten(Node *k , vector<Node*> &ldc) {
    // 中序遍历展开以 k 节点为根子树
    if (k == &zero) return;
    Rbu_Flatten(k->ls, ldc);
    if (k->wn){
        ldc.push_back(k);
    }
    // 若当前节点已删除则不保留
    Rbu_Flatten(k->rs, ldc);
}

Node* Rbu_Build(vector<Node*> &ldr,int l, int r) {
    // 将 ldr[] 数组内 [l, r) 区间重建成树，返回根节点
    int mid = (l + r) >> 1;  // 选取中间为根使其平衡
    if (l >= r) return &zero;
    ldr[mid]->ls = Rbu_Build(ldr,l, mid);
    ldr[mid]->rs = Rbu_Build(ldr,mid + 1, r);  // 建左右子树
    Calc(ldr[mid]);
    return ldr[mid];
}

void Rbu(Node *k) {
    // 重构节点 k 的全过程
    vector<Node *> ldc ;
    Rbu_Flatten(k, ldc);
    k = Rbu_Build(ldc,0, ldc.size());
}




inline bool CanRbu(Node *k) {
    // 判断节点 k 是否需要重构

    return false;
    return k->wn && (alpha * (k->tree_size) <= (double)std::max((k->ls)->tree_size, (k->rs)->tree_size) ||
                     (double)k->sd <= alpha * (k->tree_size));
}
void Del(Node *k, int p) {
    // 从以 k 为根子树移除权值为 p 节点
    if (k == &zero)
        return;
    else {
        if (k->res == p) {
            if (k->wn) (*k).wn--;
        } else {
            if (k->res < p)
                Del(k->rs, p);
            else
                Del(k->ls, p);
        }
        Calc(k);
        if (CanRbu(k)) Rbu(k);
    }
}

int MyUprBd(Node *k, int p) {
    // 在以 k 为根子树中，大于 p 的最小数的名次
    if (k == &zero)
        return 1;
    else if (k->res == p && k->wn)
        return k->ls->sz + k->wn + 1 ;
    else if (p < k->res)
        return MyUprBd(k->ls, p);
    else
        return k->ls->sz + k->wn + MyUprBd(k->rs, p);
}


int MyUprGrt(Node *k, int p) {
    // 在以 k 为根子树中，小于 p 的最大数的名次
    if (k == &zero)
        return 0;
    else if (k->res == p && k->wn)
        return k->ls->sz ;
    else if (p > k->res)
        return k->ls->sz + k->wn + MyUprGrt(k->rs, p);
    else
        return MyUprGrt(k->ls, p);
}

int MyAt(Node *k, int p) {
    // 以 k 为根的子树中，名次为 p 的权值

    if (k == &zero)
        return 0;
    else if (k->ls->sz < p && p <= k->ls->sz  + k->wn )
        return k->res;
    else if ( k->ls->sz  + k->wn < p)
        return MyAt(k->rs, p - (k->ls->sz  + k->wn));
    else
        return MyAt(k->ls, p);
}

Node* Ins(Node *k , int p){
    if(k == &zero){
        k = getFreeNode(p);
        return k;
    }
    if(k->res == p){
        //结果添加
        k->wn +=1;
    }
    else if(k->res > p){
        k->ls = Ins( k->ls  , p);
    }else{
        k->rs = Ins(k->rs , p);
    }
    Calc(k);
    if (CanRbu(k)) Rbu(k);
    return k;
}


inline int MyPre(Node *k, int p) { return MyAt(k, MyUprGrt(k, p)); }
inline int MyPost(Node *k, int p) { return MyAt(k, MyUprBd(k, p)); }

Node *head = &zero;
void run(){

    int x,y;
    scanf("%d %d",&x,&y);
    if(x == 1){
        head = Ins(head , y);
    }
    else if(x == 4){
        cout<<MyAt(head , y)<<endl;
    }
    else if(x==2){
        Del(head,y);
    }else if(x == 3 ){
        cout<< MyUprGrt(head, y) + 1<<endl;
    }else if(x == 5){
        cout<<MyPre(head,y)<<endl;
    }else if(x==6){
        cout<<MyPost(head,y)<<endl;
    }

}


int main(){
    //freopen("./slyar.in", "r+", stdin);
    //freopen("./slyar.out", "w+", stdout);

    for(int i = 0 ; i < MAXN ; ++i){
        freeNode.push(&allNode[i]);
    }
    int T;
    cin>>T;
    while(T--){
        run();
    }
}