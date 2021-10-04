/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenys <mdenys@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:12:33 by mdenys            #+#    #+#             */
/*   Updated: 2021/05/24 19:43:57 by mdenys           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_HEADER_H
# define PHILO_HEADER_H

# define _SLEEP_STEP 50
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# define _SEM_NAME_FORKS "pSemForks"
# define _SEM_WRITE_LOCK "write"

typedef struct s_philo_data	t_philo_data;

typedef struct s_all
{
	int				nbr_phils;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				etarate_meal;
	time_t			start_time;
	t_philo_data	*data_philo;
	sem_t			*write;
	sem_t			*bullet;
	sem_t			*bullets;
	int				smert;
	int				opt;
	sem_t			*bucket;
}					t_all;

typedef struct s_philo
{
	unsigned			worked :1;
	unsigned			can_run_simulation :1;
	pthread_t			thread;
	int					count_eat;
	time_t				time_to_die;
	int					died;
	int					nbr_philo;
	time_t				last_eat;
	time_t				limit;
	t_all				*all_struct;
	int					is_eat;
	int					each_eat;
	sem_t				*eat_sem;
	pid_t				pid;
	char				*name;
}					t_philo;

typedef struct s_philo_data
{
	sem_t					*sems;
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
void				*run_all_phils(t_all *all);
void				messages(t_all *all, t_philo *philo, char *str);
void				cycle(t_philo *philo);
void				ft_msleep(time_t interval_ms);
void				my_usleep(long time);
int					ft_exit(t_all *all, int ret);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
sem_t				*reopen_sem(const char *name, int value);
char				*sem_set_name(char *str, int i);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strlen(char *str);
void				get_data_for_philo(t_all *all);
int					run_observer(t_all *all);
void				pkill_all(t_all *all);
void				*obs_phil(t_philo *philo);
int					run_observer_return(t_all *all, int i);
int					check_eat(t_all *all);
#endif
