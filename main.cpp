#include <bits/stdc++.h>
#include "unda/word.hpp"

using namespace std::literals;

#ifdef	_WIN32
#error	"暂不支持 windows, 永不支持 windows. 最简单的解决方案是使用 wsl"
#elif	__GNUC__ < 16
#error	"您的编译器不支持 c++26, unda::word 类需要 c++26"
#elif	__cplusplus <= 202302l
#error	"请使用 c++26 编译"
#endif

void	review(void) {
	std::locale::global(std::locale(""));
	std::ifstream rev("sql/rev.md");
	rev.imbue(std::locale(""));
	unda::word word, mean;

	auto _ = std::system("clear");

	while (rev >> word >> mean) {
		std::println("请输入 {} 对应的英文: ", mean.c_str());

		unda::word in;
		std::cin >> in;

		long tot_in = 1l;

		while (in != word) {
			std::println("wrong answer");
			std::print("提示: ");

			if (3l <= tot_in)
				for (std::size_t x = 0uz; x + 3uz <= tot_in && x < word.len(); ++x)
					std::print("{}", word.c_str()[x]);

			std::println("\n请输入 {} 对应的英文: ", mean.c_str());

			std::cin >> in;

			tot_in++;
		}

		std::println("accepted");
		auto _ = std::system("clear");
	}
}

void	learn(long max_wordz) {
	std::locale::global(std::locale(""));
	std::ifstream need("sql/need.md");
	need.imbue(std::locale(""));
	unda::word word, mean;

	auto _ = std::system("clear");

	for (long tot_wordz = 1l; tot_wordz <= max_wordz && need >> word >> mean; ++tot_wordz) {
		std::println("{} {}", word.c_str(), mean.c_str());

		std::this_thread::sleep_for(std::chrono::seconds(2l));
		auto _ = std::system("clear");

		std::println("请输入 {} 对应的英文: ", mean.c_str());

		unda::word in;
		std::cin >> in;

		long tot_in = 1l;

		while (in != word) {
			std::println("wrong answer");
			std::print("提示: ");

			if (3l <= tot_in)
				for (std::size_t x = 0uz; x + 3uz <= tot_in && x < word.len(); ++x)
					std::print("{}", word.c_str()[x]);

			std::println("\n请输入 {} 对应的英文: ", mean.c_str());

			std::cin >> in;

			tot_in++;
		}

		std::println("accepted");
		auto _ = std::system("clear");
	}
}

void	clear(long max_wordz) {
	if (max_wordz <= 0)
		return;

	unda::word cmd{std::format("head -n {} 'sql/need.md' >> 'sql/rev.md' && sed -i '1,{}d' 'sql/need.md'", max_wordz, max_wordz)};
	auto _ = std::system(cmd.c_str());
}

void	solve(void) {
	review();

	std::println("今天学几个单词?");
	long max_wordz;
	std::cin >> max_wordz;

	for (long tot_learn = 1l; tot_learn <= 3l; ++tot_learn)
		learn(max_wordz);

	std::println("恭喜完成了今天的背单词任务. keep it, 你一定能在四六级都获得满分");
	std::println("");
	std::println("抽奖中");

	clear(max_wordz);

	std::println("抽奖完成, 你抽到了:");
	std::println("macbook pro m18");
}

signed	main(void) {
//	std::freopen(".in", "r", stdin);
//	std::freopen(".out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	long _ = 1;

//	_ = nxt();

	while (_--)
		solve();

	std::cout.flush();
	return EXIT_SUCCESS;
}
