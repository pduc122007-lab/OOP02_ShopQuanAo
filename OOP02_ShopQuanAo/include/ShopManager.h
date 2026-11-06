#ifndef SHOPMANAGER_H
#define SHOPMANAGER_H
#include <string>
#include <vector>
using namespace std;
template <typename T>
class ShopManager{
	private:
		vector<T*> items;
	public:
		ShopManager(){
		}
		~ShopManager(){
			for(auto item:items){
				delete item;
			}
			items.clear();
		}
		void add(T* item){
			items.push_back(item);
		}
		T* findById(string id){
			for(auto item:items){
				if(item->getId() == id){
					return item;
				}
			}
			return nullptr;
		}
		vector<T*>& getAll(){
			return items;
		}
		int size()const{
			return items.size();
		}
};
#endif
