/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 21:18:22 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/24 19:16:16 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_HEADER_H
# define PHILO_HEADER_H

# define _SLEEP_STEP 20
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <string.h>

typedef struct s_philo_data	t_philo_data;

typedef struct s_all
{
	int				nbr_phls;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				iteration_eat;
	time_t			start_time;
	t_philo_data	*data;
	pthread_mutex_t	write;
	int				smert;
	int				opt;
}					t_all;

typedef struct s_philo
{
	unsigned			worked :1;
	unsigned			can_run_simulation :1;
	int					more_fork;
	int					less_fork;
	pthread_t			thread;
	int					count_eat;
	time_t				time_to_die;
	int					nbr_philo;
	int					eat_etarate;
	time_t				last_eat;
	time_t				limit;
	t_all				*all_struct;
	pthread_mutex_t		eat_mutex;
}						t_philo;

typedef struct s_philo_data
{
	pthread_mutex_t			*mutex;
	t_philo					*philors;
}							t_philo_data;

void				*ft_calloc(size_t num, size_t size);
t_all				*structalloc_and_bzero(void);
int					parse_and_check_values(char **argv, int quantity);
int					ft_atoi(const char *str);
int					check_f(char ch);
int					runner(t_all *all);
int					return_big(int a, int b);
int					return_less(int a, int b);
time_t				ft_get_time(void);
void				*run_trhead(t_philo *philo);
int					prepare_resources(t_all *all);
int					check_all_run(t_all *all);
void				run_simulation(t_all *all);
void				run_all_phils(t_all *all);
void				messages(t_all *all, t_philo *philo, char *str);
void				cycle(t_philo *philo);
void				ft_msleep(time_t interval_ms);
void				my_usleep(long time);
int					ft_exit(t_all *all);
int					check_param(t_all *all, int optional);
int					check_eat(t_all *all);
#endif
