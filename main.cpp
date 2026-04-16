#include <bits/stdc++.h>

using namespace std::literals;

void	review(void) {
	std::locale::global(std::locale(""));
	std::ifstream rev("sql/rev.md");
	rev.imbue(std::locale(""));
	std::string word, mean;

	auto _ = std::system("clear");

	while (rev >> word >> mean) {
		std::println("请输入 {} 对应的英文: ", mean);

		std::string in;
		std::cin >> in;

		long tot_in = 1l;

		while (in != word) {
			std::println("wrong answer");
			std::print("提示: ");

			if (3l <= tot_in)
				for (std::size_t x = 0uz; x + 3uz <= tot_in && x < word.length(); ++x)
					std::print("{}", word[x]);

			std::println("\n请输入 {} 对应的英文: ", mean);

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
	std::string word, mean;

	auto _ = std::system("clear");

	for (long tot_wordz = 1l; tot_wordz <= max_wordz && need >> word >> mean; ++tot_wordz) {
		std::println("{} {}", word, mean);

		std::this_thread::sleep_for(2s);
		auto _ = std::system("clear");

		std::println("请输入 {} 对应的英文: ", mean);

		std::string in;
		std::cin >> in;

		long tot_in = 1l;

		while (in != word) {
			std::println("wrong answer");
			std::print("提示: ");

			if (3l <= tot_in)
				for (std::size_t x = 0uz; x + 3uz <= tot_in && x < word.length(); ++x)
					std::print("{}", word[x]);

			std::println("\n请输入 {} 对应的英文: ", mean);

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

	std::string cmd{std::format("head -n {} 'sql/need.md' >> 'sql/rev.md' && sed -i '1,{}d' 'sql/need.md'", max_wordz, max_wordz)};
	auto _ = std::system(cmd.c_str());
}

void	solve(void) {
	review();

	std::println("今天学几个单词?");
	long max_wordz;
	std::cin >> max_wordz;

	for (long tot_learn = 1l; tot_learn <= 3l; ++tot_learn)
		learn(max_wordz);

	clear(max_wordz);
}

signed	main(void) {
	solve();
	return EXIT_SUCCESS;
}
