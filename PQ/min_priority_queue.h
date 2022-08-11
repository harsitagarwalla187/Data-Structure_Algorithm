#include<vector>

using namespace std;

class priorityQueue{

        vector<int> pq;

    public:
        
        priorityQueue() {
        }

        bool isEmpty() {
            return pq.size()==0;
        }

        int getSize() {
            return pq.size();
        }

        int getMin() {
            if(isEmpty()) return 0;
            else          return pq[0];
        }

        void insert(int val) {
            pq.push_back(val);
            int cI = pq.size()-1;

            while(cI>0) {
                int pI = (cI-1)/2;
                if(pq[pI] > pq[cI]) {
                    int temp = pq[cI];
                    pq[cI]   = pq[pI];
                    pq[pI]   = temp;
                } else {
                    break;
                }
                cI = pI;
            }
        }

        int removeMin() {
            if(isEmpty()) return 0;
            int ans = pq[0];
            pq[0]   = pq[pq.size()-1];
            pq.pop_back();

            int pI  = 0;
            int lcI = 2*pI+1;
            int rcI = 2*pI+2;

            while(lcI < pq.size()) {
                int minI = pI;
                if(pq[minI] > pq[lcI]) minI = lcI;
                if(pq[minI] > pq[rcI]) minI = rcI;
                if(pI == minI) break;
                else {
                    int temp = pq[minI];
                    pq[minI] = pq[pI];
                    pq[pI]   = temp;
                }
                pI  = minI;
                lcI = 2*pI+1;
                rcI = 2*pI+2; 
            }
            return ans;
        }
};