#include <bits/stdc++.h>

using namespace std::literals;

void	chk(const std::string &word, const std::string &mean) {
	std::println("请输入 {} 对应的英文: ", mean);
	std::string in;
	std::cin >> in;

	long tot_in = 1z;

	while (in != word) {
		std::println("wrong answer");
		std::print("提示: ");

		// 给 typing error 两次机会, 从第三次出错开始提示第 0 字, 然后每次多提示一个字
		for (std::size_t x = 0uz; x + 3uz <= tot_in && x < word.length(); ++x)
			std::print("{}", word[x]);

		std::println("\n请输入 {} 对应的英文: ", mean);

		std::cin >> in;

		tot_in++;
	}

	auto _ = std::system("clear");
}

void	review(void) {
	std::ifstream rev("sql/rev.md");
	rev.imbue(std::locale(""));
	std::string word, mean;

	auto _ = std::system("clear");

	while (rev >> word >> mean)
		chk(word, mean);
}

void	learn(long max_wordz)
	pre(0z < max_wordz) {
	std::ifstream need("sql/need.md");
	need.imbue(std::locale(""));
	std::string word, mean;

	auto _ = std::system("clear");

	for (long tot_wordz = 1z; tot_wordz <= max_wordz && need >> word >> mean; ++tot_wordz) {
		std::println("{} {}", word, mean);

		std::this_thread::sleep_for(2s);
		auto _ = std::system("clear");

		chk(word, mean);
	}
}

void	clear(long max_wordz)
	pre(0z < max_wordz) {
	std::string cmd{std::format("head -n {} 'sql/need.md' >> 'sql/rev.md' && sed -i '1,{}d' 'sql/need.md'", max_wordz, max_wordz)};
	auto _ = std::system(cmd.c_str());
}

void	work(long max_wordz)
	pre(0z < max_wordz) {
	std::ifstream rev("sql/rev.md");
	rev.imbue(std::locale(""));
	std::string word, mean;
	std::deque<std::tuple<std::string, std::string>> q;

	while (rev >> word >> mean)
		q.emplace_back(word, mean);

	if (max_wordz < q.size())
		q.erase(q.begin(), q.begin() + q.size() - max_wordz);

	for (auto &[word, mean] : q)
		chk(word, mean);
}

void	solve(void) {
	std::locale::global(std::locale(""));

	review();

	std::println("今天学几个单词?");
	long max_wordz;
	std::cin >> max_wordz;

	learn(max_wordz);
	learn(max_wordz);
	clear(max_wordz);

	for (long tot_learn = 0z; tot_learn < 3z; ++tot_learn)
		work(max_wordz);
}

signed	main(void) {
	solve();
	return EXIT_SUCCESS;
}
