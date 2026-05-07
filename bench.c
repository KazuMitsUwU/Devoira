/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitrakaa <sitrakaa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 07:45:50 by sitrakaa          #+#    #+#             */
/*   Updated: 2026/05/07 09:59:43 by sitrakaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Parce qu'en C on ne peut pas passer plusieurs choses en un seul argument sans
les emballer dans une struct. Il n'y a pas d'autre moyen.
Si tu veux passer `stack_a`, `stack_b`, et `bench` en un seul argument, tu **dois
* les mettre dans une struct d'abord. C'est comme ça que C fonctionne —
contrairement à Python ou JavaScript où tu pourrais passer
 un dictionnaire ou un objet, en C la struct est le
 seul moyen de regrouper des variables
ensemble et de les passer comme une seule unité.*/
