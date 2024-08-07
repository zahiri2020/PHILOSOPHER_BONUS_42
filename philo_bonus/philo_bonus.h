/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezahiri <ezahiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:02:17 by ezahiri           #+#    #+#             */
/*   Updated: 2024/07/02 10:18:55 by ezahiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct s_data
{
	int				n_philo;
	long			t_eat;
	long			t_dead;
	long			t_sleep;
	long			n_mails;
	sem_t			*fork;
	sem_t			*death;
	sem_t			*full;
	sem_t			*print;
	long			t_start;
	pid_t			*pid;
}				t_data;

typedef struct s_philo
{
	int				id;
	pid_t			pid;
	t_data			*info;
	sem_t			*sm_last_eat;
	long			last_eat;
	long			n_count;
}				t_philo;

long	ft_atoi(const char *str);
int		init_data(char **av, t_philo **p);
int		create_process(t_philo *p);
void	ft_sleep(long time);
long	get_time(void);
void	eating(t_philo *p);
void	sleeping(t_philo *p);
void	thinking(t_philo *p);
void	ft_handler(t_data *info, int n);
void	sem_clean(sem_t *s, char *name);

#endif