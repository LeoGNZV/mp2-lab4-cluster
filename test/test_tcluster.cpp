#include "Cluster.h"

#include <gtest.h>
TEST(TCluster, can_create_cluster)
{
	struct programm y1 = { "78923", 0, 18, 9 };
	struct programm y2 = { "78623", 0, 24, 7 };
	struct programm y3 = { "72323", 0, 36, 5 };
	struct programm y4 = { "75623", 0, 48, 3 };
	vector<programm> n = { y1, y2, y3, y4 };
	ASSERT_NO_THROW(Cluster q(64, 0.8, n, 2));
}
TEST(TCluster, cant_create_cluster_with_uncorrect_number_of_processor)
{
	struct programm y1 = { "78923", 0, 18, 9 };
	struct programm y2 = { "78623", 0, 24, 7 };
	struct programm y3 = { "72323", 0, 36, 5 };
	struct programm y4 = { "75623", 0, 48, 3 };
	vector<programm> n = { y1, y2, y3, y4 };
	ASSERT_ANY_THROW(Cluster q(10, 0.8, n, 2));
}
TEST(TCluster, cant_create_cluster_with_the_number_of_possible_programs)
{
	struct programm y1 = { "78923", 0, 18, 9 };
	struct programm y2 = { "78623", 0, 24, 7 };
	struct programm y3 = { "72323", 0, 36, 5 };
	struct programm y4 = { "75623", 0, 48, 3 };
	vector<programm> n = { y1, y2, y3, y4 };
	ASSERT_ANY_THROW(Cluster q(10, 0.8, n, -1));
}
TEST(TCluster, cant_create_cluster_with_impossible_number_of_threshold_for_the_appearance_of_the_program)
{
	struct programm y1 = { "78923", 0, 18, 9 };
	struct programm y2 = { "78623", 0, 24, 7 };
	struct programm y3 = { "72323", 0, 36, 5 };
	struct programm y4 = { "75623", 0, 48, 3 };
	vector<programm> n = { y1, y2, y3, y4 };
	ASSERT_ANY_THROW(Cluster q(64, 1.4, n, 2));
}

TEST(TCluster, there_are_programs_that_cannot_be_executed_on_the_cluster_with_so_many_processors)
{
	struct programm y1 = { "78923", 0, 18, 9 };
	struct programm y2 = { "78623", 0, 24, 7 };
	struct programm y3 = { "72323", 0, 36, 5 };
	struct programm y4 = { "75623", 0, 48, 3 };
	vector<programm> n = { y1, y2, y3, y4 };
	ASSERT_ANY_THROW(Cluster q(24, 0.8, n, 2));
}

TEST(TCluster, can_start_a_cluster)
{
	struct programm y1 = { "78923", 0, 18, 9 };
	struct programm y2 = { "78623", 0, 24, 7 };
	struct programm y3 = { "72323", 0, 36, 5 };
	struct programm y4 = { "75623", 0, 48, 3 };
	vector<programm> n = { y1, y2, y3, y4 };
	Cluster q(64, 0.8, n, 2);
	ASSERT_NO_THROW(q.Starting—luster(47));
}
TEST(TCluster, cant_start_a_cluster_with_negative_value_of_tact_work_max)
{
	struct programm y1 = { "78923", 0, 18, 9 };
	struct programm y2 = { "78623", 0, 24, 7 };
	struct programm y3 = { "72323", 0, 36, 5 };
	struct programm y4 = { "75623", 0, 48, 3 };
	vector<programm> n = { y1, y2, y3, y4 };
	Cluster q(64, 0.8, n, 2);
	ASSERT_ANY_THROW(q.Starting—luster(-9));
}
TEST(TCluster, can_get_result_of_strting_cluster)
{
	struct programm y1 = { "78923", 0, 18, 9 };
	struct programm y2 = { "78623", 0, 2, 7 };
	struct programm y3 = { "72323", 0, 6, 5 };
	struct programm y4 = { "75623", 0, 8, 3 };
	vector<programm> n = { y1, y2, y3, y4 };
	Cluster q(64, 0.8, n, 2);
	q.Starting—luster(10);
	ASSERT_NO_THROW(q.get_result());
}