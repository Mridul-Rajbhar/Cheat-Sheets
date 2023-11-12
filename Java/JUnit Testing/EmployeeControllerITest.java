package com.assignment.task.integration;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.Mockito.when;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.post;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.put;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.junit.jupiter.MockitoExtension;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.context.SpringBootTest.WebEnvironment;
import org.springframework.http.MediaType;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.ResultActions;
import org.springframework.test.web.servlet.result.MockMvcResultHandlers;
import org.springframework.test.web.servlet.result.MockMvcResultMatchers;

import com.assignment.task.entities.Address;
import com.assignment.task.entities.Employee;
import com.assignment.task.entities.Gender;
import com.assignment.task.entities.Role;
import com.assignment.task.repositoriesImpl.EmployeeRepositoryImpl;
import com.assignment.task.supportingClass.ResponseMultipleRecordsCreated;
import com.assignment.task.supportingClass.ResponseUpdateRecords;
import com.fasterxml.jackson.databind.ObjectMapper;

@SpringBootTest(webEnvironment = WebEnvironment.RANDOM_PORT)
@AutoConfigureMockMvc
class EmployeeControllerITest {

	@Autowired
	private MockMvc mockMvc;
	
	@Autowired
	private EmployeeRepositoryImpl employeeRepositoryImpl;
	
	@Autowired
	private ObjectMapper objectMapper;
	
	void setup() {
		
	}
	
	
	@Test
	@DisplayName("Test post employee url positive scenario")
	public void givenEmployeeList_whenPostEmployee_thenCreateEmployee() throws Exception {
		//setup
		Address add1 = new Address("B/6 Shalimar", "Vakola Road", "Mumbai", "Maharashtra","India","123456");
		
		Employee emp1 = new Employee("Mridul","Rajbhar",22,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		Employee emp2 = new Employee("john","dzosa",12,Role.MANAGER,Gender.MALE, LocalDate.of(2000, 9, 12));
		Employee emp3 = new Employee("  ", "dzosa", 22, Role.ACCOUNTS, Gender.MALE, LocalDate.of(2000, 9, 12));
		emp1.setAddress(add1);
		emp2.setAddress(add1);
		emp3.setAddress(add1);
		
		List<Employee> employeeList = new ArrayList<Employee>();	
		employeeList.add(emp1);employeeList.add(emp2);employeeList.add(emp3);
		
		ResponseMultipleRecordsCreated<Employee> responseListCreate = new ResponseMultipleRecordsCreated<Employee>();
		responseListCreate.setRecordsInserted(3);
		responseListCreate.setRecordsRead(employeeList.size());
		responseListCreate.setSuccess(employeeList);
		
		
		//act
		ResultActions response = mockMvc.perform(post("/save/employees")
				.contentType(MediaType.APPLICATION_JSON)
				.accept(MediaType.APPLICATION_JSON)
				.content(objectMapper.writeValueAsString(employeeList)));
		
		
		//assert 
		response.andDo(MockMvcResultHandlers.print())
			.andExpect(MockMvcResultMatchers.status().isCreated())
			.andExpect(MockMvcResultMatchers.content().contentType("application/json"))
			.andExpect(MockMvcResultMatchers.jsonPath("$.success.size()").value(1));
	}
	
	
	@Test
	@DisplayName("Test get employee by id url positive scenario")
	public void givenEmployee_whenGetEmployeeById_thenReturnEmployee() throws Exception {
		//setup
		Address add1 = new Address("B/6 Shalimar", "Vakola Road", "Mumbai", "Maharashtra","India","123456");
		Employee emp1 = new Employee("Mridul","Rajbhar",22,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		emp1.setAddress(add1);
		
		Employee savedEmployee = employeeRepositoryImpl.saveEmployee(emp1);
		
		//act
		ResultActions response = mockMvc.perform(get("/employees/employee/{id}",savedEmployee.getId())
				.contentType(MediaType.APPLICATION_JSON)
				.accept(MediaType.APPLICATION_JSON)
				.content(objectMapper.writeValueAsString(emp1)));
		
		//assert 
		response.andDo(MockMvcResultHandlers.print())
			.andExpect(MockMvcResultMatchers.status().isOk())
			.andExpect(MockMvcResultMatchers.content().contentType("application/json"))
			.andExpect(MockMvcResultMatchers.jsonPath("$.firstname").value(emp1.getFirstname()));
	}


	@Test
	@DisplayName("Test get employee by id url negative scenario")
	public void givenEmployee_whenGetEmployeeById_thenReturnNothing() throws Exception {
		//setup
		
		
		//act
		ResultActions response = mockMvc.perform(get("/employees/employee/{id}",1)
				.contentType(MediaType.APPLICATION_JSON)
				.accept(MediaType.APPLICATION_JSON));
		
		//assert 
		response.andDo(MockMvcResultHandlers.print())
			.andExpect(MockMvcResultMatchers.status().isNotFound());
	}

	
	@Test
	public void givenEmployee_whenUpdateEmployee_thenReturnUpdateResponseTrue() throws Exception{
		//setup
		
		Address add1 = new Address("B/6 Shalimar", "Vakola Road", "Mumbai", "Maharashtra","India","123456");
		Employee emp1 = new Employee("Mridul","Rajbhar",23,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		emp1.setAddress(add1);

		employeeRepositoryImpl.saveEmployee(emp1);
		
		Address updatedAdd1 = new Address("B/6 Shalimar", "Vakola Road", "Pune", "Maharashtra","India","123456");
		Employee updatedEmp1 = new Employee("Mridul","Rajbhar",23,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		updatedEmp1.setAddress(updatedAdd1);
		updatedEmp1.getAddress().setId(emp1.getAddress().getId());
		updatedEmp1.setId(emp1.getId());
		
		ResponseUpdateRecords updatedResponse = new ResponseUpdateRecords();
		updatedResponse.setSuccess(true);
		
		//act
		ResultActions response = mockMvc.perform(put("/update/employees")
						.contentType(MediaType.APPLICATION_JSON)
						.accept(MediaType.APPLICATION_JSON)
						.content(objectMapper.writeValueAsString(updatedEmp1)));
		
		System.out.println(response);
		//assert 
		response.andDo(MockMvcResultHandlers.print())
					.andExpect(MockMvcResultMatchers.status().isOk())
					.andExpect(MockMvcResultMatchers.jsonPath("$.success").value(true));
	}
	
	
	@Test
	public void givenEmployee_whenUpdateEmployee_thenReturnUpdateResponseFalse() throws Exception{
		//setup
		
		Address add1 = new Address("B/6 Shalimar", "Vakola Road", "Mumbai", "Maharashtra","India","123456");
		Employee emp1 = new Employee("Mridul","Rajbhar",23,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		emp1.setAddress(add1);

		employeeRepositoryImpl.saveEmployee(emp1);
	
		Address updatedAdd1 = new Address("B/6 Shalimar", "Vakola Road", "Pune", "Maharashtra","India","123456");
		Employee updatedEmp1 = new Employee("Mridul","Rajbhar",23,Role.JR_ENGINEER,Gender.MALE, LocalDate.of(2000, 9, 12));
		updatedEmp1.setAddress(updatedAdd1);
		updatedEmp1.setId(2);
		
		ResponseUpdateRecords updatedResponse = new ResponseUpdateRecords();
		updatedResponse.setSuccess(false);
		
		System.out.println(updatedEmp1);
		
		//act
		ResultActions response = mockMvc.perform(put("/update/employees")
						.contentType(MediaType.APPLICATION_JSON)
						.accept(MediaType.APPLICATION_JSON)
						.content(objectMapper.writeValueAsString(updatedEmp1)));
		
		System.out.println(response);
		//assert 
		response.andDo(MockMvcResultHandlers.print())
					.andExpect(MockMvcResultMatchers.status().isNotAcceptable())
					.andExpect(MockMvcResultMatchers.jsonPath("$.success").value(false));
	}

	
}
