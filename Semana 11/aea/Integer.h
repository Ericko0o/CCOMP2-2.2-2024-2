#ifndef __INTEGER_H__
#define __INTEGER_H__
class Integer{
    private:
        int val;
    public:
        Integer(int val = 0) {
            this->setVal(val);
        }
        int getVal() const {
            return val;
        }
        void setVal(int val) {
            this->val = val;
        }
};
#endif


