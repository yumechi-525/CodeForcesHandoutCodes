def solve():
    n = int(input())
    input_list = [int(c) for c in input().split()][::-1]
    number_list = []
    print_list = []
    start_num, list_sum = 1, 0
    for num, idx in zip(input_list, range(n)):
        number_list.append(num)
        list_sum += num
        if list_sum == (start_num + (idx + 1)) * ((idx - start_num) + 2) // 2:
            print_list.append(" ".join(sorted([str(i) for i in number_list], reverse=True)))
            next_line_count = len(number_list) - 1
            if next_line_count > 0:
                print_list.append("\n" * (next_line_count - 1))
            next_line_counter, list_sum, start_num = 0, 0, idx + 2
            number_list = []

    if(len(number_list) > 0):
        print_list.append(" ".join(sorted([str(i) for i in number_list], reverse=True)))
        next_line_count = len(number_list) - 1
        if next_line_count > 0:
            print_list.append("\n" * (next_line_count - 1))
    print("\n".join(print_list[::-1]))

if __name__=="__main__":
    solve()