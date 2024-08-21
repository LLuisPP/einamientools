ft_usleep(philo, philo->params->time_to_eat / 2 * (philo->id % 2));

void	ft_usleep(t_philo *philo, int for_time)
{
	long long	start;

	start = ft_timestamp_philo(philo);
	while (start + for_time > ft_timestamp_philo(philo))
		usleep(100);
}
