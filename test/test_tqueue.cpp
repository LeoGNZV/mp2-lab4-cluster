#include "Cluster.h"

#include <gtest.h>

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<programm> q);
}
TEST(TQueue, can_add_a_value_in_queue)
{
	TQueue<programm> q;
	struct programm y = { "78923", 0, 18, 9};
	ASSERT_NO_THROW(q.Push(y));
}
TEST(TQueue, resulting_size_is_the_same_as_the_real_one)
{
	TQueue<programm> q;
	struct programm y = { "78923", 0, 18, 9 };
	q.Push(y);
	EXPECT_EQ(1, q.get_size());
}
TEST(TQueue, empty_queue_is_empty)
{
	TQueue<programm> q;
	EXPECT_EQ(1, q.IsEmpty());
}
TEST(TQueue, checking_for_the_emptiness_of_a_nonempty_queue)
{
	TQueue<int> q;
	q.Push(901);
	EXPECT_EQ(0, q.IsEmpty());
}
TEST(TQueue, can_get_the_value_from_the_beginning_of_the_queue_and_this_value_is_correct)
{
	TQueue<int> q;
	q.Push(901);
	EXPECT_EQ(901, q.Top());
}
TEST(TQueue, can_delete_value_from_the_beginning_of_the_queue)
{
	TQueue<int> q;
	q.Push(901);
	ASSERT_NO_THROW(q.Pop());
}