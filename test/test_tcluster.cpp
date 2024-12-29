#include "Cluster.h"

#include <gtest.h>
TEST(TCluster, can_create_cluster)
{
	ASSERT_NO_THROW(Cluster q(64, 0.8, 2));
}
TEST(TCluster, cant_create_cluster_with_uncorrect_number_of_processor)
{
	ASSERT_ANY_THROW(Cluster q(10, 0.8, 2));
}
TEST(TCluster, cant_create_cluster_with_the_number_of_possible_programs)
{
	ASSERT_ANY_THROW(Cluster q(10, 0.8, -1));
}
TEST(TCluster, cant_create_cluster_with_impossible_number_of_threshold_for_the_appearance_of_the_program)
{
	ASSERT_ANY_THROW(Cluster q(64, 1.4, 2));
}

TEST(TCluster, can_start_a_cluster)
{
	Cluster q(64, 0.8, 2);
	ASSERT_NO_THROW(q.Starting—luster(47));
}
TEST(TCluster, cant_start_a_cluster_with_negative_value_of_tact_work_max)
{
	Cluster q(64, 0.8, 2);
	ASSERT_ANY_THROW(q.Starting—luster(-9));
}
TEST(TCluster, can_get_result_of_strting_cluster)
{
	Cluster q(64, 0.8, 2);
	q.Starting—luster(10);
	ASSERT_NO_THROW(q.get_result());
}