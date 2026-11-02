
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    char data;
    int freq;
    Node *left,*right;

    Node(char d,int f)
    {
        data=d;
        freq=f;
        left=right=NULL;
    }
};

struct Compare
{
    bool operator()(Node* a,Node* b)
    {
        return a->freq>b->freq;
    }
};

void printCodes(Node* root,string code)
{
    if(root==NULL)
    {
        return;
    }

    if(root->left==NULL && root->right==NULL)
    {
        if(code.empty())
        {
            cout<<root->data<<" : "<<"0"<<endl;
        }
        else
        {
            cout<<root->data<<" : "<<code<<endl;
        }

        return;
    }

    printCodes(root->left,code+"0");
    printCodes(root->right,code+"1");
}

int main()
{
    int n;
    char ch;
    int freq;

    priority_queue<Node*,vector<Node*>,Compare> pq;

    cout<<"Enter number of characters: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter character and frequency: ";
        cin>>ch>>freq;

        pq.push(new Node(ch,freq));
    }

    while(pq.size()>1)
    {
        Node* left=pq.top();
        pq.pop();

        Node* right=pq.top();
        pq.pop();

        Node* top=new Node('$',left->freq+right->freq);

        top->left=left;
        top->right=right;

        pq.push(top);
    }

    cout<<"\nHuffman Codes:\n";

    printCodes(pq.top(),"");

    return 0;
}

/*
A greedy algorithm is an approach for solving a problem by selecting the best option
available at the moment. It doesn't worry whether the current best result will bring the
overall optimal result.
Advantages of Greedy Approach
 The algorithm is easier to describe.
 This algorithm can perform better than other algorithms (but, not in all cases).
Disadvantages of Greedy Approach
 As mentioned earlier, the greedy algorithm doesn't always produce the optimal
solution. This is the major disadvantage of the algorithm
 For example, suppose we want to find the longest path in the graph below from root
to leaf.
*/

/*
Huffman Encoding is a lossless data compression algorithm that assigns variable-length binary codes to characters based on their frequencies.
- Characters with higher frequency get shorter codes.
- Characters with lower frequency get longer codes.
- Each character receives a unique prefix-free binary code.
algorithm
Algorithm – Huffman Encoding
1. Start.
2. Read the characters and their frequencies.
3. Create a leaf node for every character.
4. Insert all nodes into a Min Heap.
5. Extract the two nodes having minimum frequencies.
6. Create a new internal node with frequency equal to their sum.
7. Make the first extracted node the left child and the second the right child.
8. Insert the new node into the Min Heap.
9. Repeat steps 5–8 until only one node remains.
10. The remaining node becomes the root of the Huffman Tree.
11. Traverse the tree:
    - Assign 0 when moving left.
    - Assign 1 when moving right.
12. Print the Huffman code whenever a leaf node is reached.
13. Stop.
Because the original data can be reconstructed exactly from the encoded data without losing any information.
File Compression: Used in ZIP and other compression formats to reduce file sizes.
Image Compression: Used in formats such as JPEG as part of the compression process.
Text Compression: Reduces the storage required for text files by assigning shorter codes to frequently occurring characters.
Audio Compression: Used in some audio coding systems to efficiently encode data.
tc-nlogn
*/
