#include <vector>
#include <functional>
#include <sstream>
#include <string> 
namespace SKC::Console::rtm {
	namespace types {
		typedef std::function<void(size_t) > menueFunc_t;
	}
	class RealTimeMenu{
		std::vector<std::string> items;
		std::vector<types::menueFunc_t> functions;
	public:
		void AddOption(std::string option, types::menueFunc_t funct) {
			items.push_back(option); 
			functions.push_back(funct); 
		 }
		void operator () (size_t option) {
			if ((option-1) > items.size()) {
				return;
			}
			functions[option-1](option-1); //this is lovely syntax... 
		}
		std::string toString() {
			auto ret = std::stringstream(); 
			for (int x = 0; x < items.size(); ++x) {
				ret << '[' << (x+1) << ']' << items[x] << '\n';
			}
			return ret.str();
		}
		void DoAt(size_t option) {
			operator()(option); 
		}
	};
}