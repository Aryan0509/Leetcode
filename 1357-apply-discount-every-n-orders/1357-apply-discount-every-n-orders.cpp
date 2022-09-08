class Cashier {
public:
    int count;
    int nn;
    unordered_map<int,int>m;
    int disc;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        count=0;
        nn=n;
        int x=products.size();
        for(int i=0;i<x;i++)
        {
            m[products[i]]=prices[i];
        }
        disc=discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        count++;
        double bill=0;
        int x=product.size();
        for(int i=0;i<x;i++)
        {
            bill+=m[product[i]]*amount[i];
        }
        if(count%nn==0)
        {
            bill=bill*(double(100-disc)/double(100));
        }
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */