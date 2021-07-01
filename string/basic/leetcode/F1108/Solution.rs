//  problem name: Defanging an IP Address
//  problem link: https://leetcode.com/problems/defanging-an-ip-address/

//  time: (?)
//  author: ratul14

//  other_tags: (?)
//  difficulty_level: beginner


impl Solution {
    pub fn defang_i_paddr(address: String) -> String {

        return str::replace(&address, ".", "[.]"); //had to borrow for compatibility between std::str ans String

    }
}
